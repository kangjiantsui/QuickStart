package tcpclient

import (
	"QuickStart/go/tcpclient-dtfish/common"
	"QuickStart/go/tcpclient-dtfish/net/codec"
	tcp2 "QuickStart/go/tcpclient-dtfish/net/tcp"
	pb "QuickStart/go/tcpclient-dtfish/proto"
	dtpb "QuickStart/go/tcpclient-dtfish/proto/dtfish"
	"QuickStart/go/utils"
	"crypto/rand"
	"encoding/base64"
	"encoding/binary"
	"fmt"
	"github.com/golang/protobuf/proto"
	"github.com/stretchr/testify/assert"
	"net"
	"sync"
	"testing"
)

func tcpClientConn() error {
	conn, err := net.Dial("tcp", "127.0.0.1:11000")
	if err != nil {
		return fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	utils.PrintJson(conn.LocalAddr())
	_, err = conn.Write([]byte{1, 2, 3, 4})
	if err != nil {
		return fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	_, err = conn.Write([]byte{1, 2, 3, 4})
	if err != nil {
		return fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	select {}
}

func TestTcpClientConn(t *testing.T) {
	err := tcpClientConn()
	if err != nil {
		t.Fatal(err.Error())
	}
}

func TestRandomAccount(t *testing.T) {
	account := randomAccount()
	utils.PrintJson(account)
	assert.EqualValues(t, 17, len(account))
}

// 生成一个长度17的随机字符串,作为登录account
func randomAccount() string {
	// 生成随机字节数组
	randomBytes := make([]byte, 17)
	_, err := rand.Read(randomBytes)
	if err != nil {
		panic(err)
	}
	// 将字节数组转换为base64编码的字符串
	randomString := base64.URLEncoding.EncodeToString(randomBytes)
	// 截取字符串的前17个字符
	randomString = randomString[:17]
	return randomString
}

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "127.0.0.1:11000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	utils.PrintJson(conn.LocalAddr())
	session := tcp2.NewSession(
		conn,
		tcp2.SessionTypeTcp,
		tcp2.NewMsgParser(),
		&codec.DTFishClientProtoProtocol{Endian_: binary.LittleEndian},
		2000,
	)
	wg := sync.WaitGroup{}
	wg.Add(1)
	var uid uint64
	go func() {
		for {
			msg, _ := session.Receive()
			if msg == nil {
				continue
			}
			resp := msg.([]interface{})
			head := resp[0].(*common.ProtocolClientHead)
			uid = head.Uid_
			t.Logf(`uid:%d,msg:%s`, head.Uid_, pb.EmCSMsgId(head.Msg_id_))
			wg.Done()
			break
		}
	}()
	loginType := dtpb.EnumLoginType_enumLoginTypeToRegisterNewUser
	gameType := dtpb.EnumGameType_enumGameTypeDouDiZhu
	account := randomAccount()
	password := "asadsadsasdasdads"
	nickname := "asadsadsasdasdads"
	gender := dtpb.EnumGender_enumGenderMale
	deviceType := dtpb.EnumDeviceType_enumDeviceTypeAndroid
	deviceID := ""
	macAddress := ""
	secureKey := ""
	channel := "xxxs"
	var version uint32 = 30000001
	dtlq := &dtpb.LoginRequest{
		LoginType:  &loginType,
		Account:    &account,
		GameType:   &gameType,
		Password:   &password,
		Nickname:   &nickname,
		Gender:     &gender,
		DeviceType: &deviceType,
		DeviceID:   &deviceID,
		MacAddress: &macAddress,
		SecureKey:  &secureKey,
		Channel:    &channel,
		Version:    &version,
	}
	loginData, err := proto.Marshal(dtlq)
	if err != nil {
		t.Fatal(err.Error())
	}
	err = session.Send(&common.ProtocolClientHead{
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_PLAYER_LOGIN),
	}, &pb.PbCsPlayerLoginReqMsg{
		LoginType:       pb.EmLoginType_Login_type_dt,
		DtfishLoginData: loginData,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	wg.Wait()
	go func() {
		for {
			msg, _ := session.Receive()
			if msg == nil {
				continue
			}
			resp := msg.([]interface{})
			head := resp[0].(*common.ProtocolClientHead)
			uid = head.Uid_
			cmd := pb.EmCSMsgId(head.Msg_id_)
			t.Logf(`uid:%d,cmd:%s`, head.Uid_, cmd)
			switch cmd {
			case pb.EmCSMsgId_CS_MSG_GAME_SHOP_PURCHASE:
				shopResp := &pb.PbCsGamePlayerShopPurchaseMsg{}
				err = proto.Unmarshal(resp[1].([]uint8), shopResp)
				if err != nil {
					t.Error(err.Error())
					return
				}
				utils.PrintJson(shopResp)
			case pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_BUY:
				jResp := &pb.JiJiaLunPanBuyResp{}
				err = proto.Unmarshal(resp[1].([]uint8), jResp)
				if err != nil {
					t.Error(err.Error())
					return
				}
				utils.PrintJson(jResp)
			case pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PLAY:
				jResp := &pb.JiJiaLunPanPlayResp{}
				err = proto.Unmarshal(resp[1].([]uint8), jResp)
				if err != nil {
					t.Error(err.Error())
					return
				}
				if !jResp.Finish {
					continue
				}
				utils.PrintJson(jResp)
			}
		}
	}()
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_SHOP_EXCHANGE_DELIVERY),
	}, &pb.PBCsGameShopExchangeDeliveryReqMsg{
		ProductId: 101010301,
		Count:     500,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK),
	}, &pb.JiJiaLunPanPickReq{
		ItemId: 4008,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK),
	}, &pb.JiJiaLunPanPickReq{
		ItemId: 14001,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK),
	}, &pb.JiJiaLunPanPickReq{
		ItemId: 4008,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK),
	}, &pb.JiJiaLunPanPickReq{
		ItemId: 9001,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}

	for i := 0; i < 200; i++ {
		err = session.Send(&common.ProtocolClientHead{
			Uid_:    uid,
			Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PLAY),
		}, &pb.JiJiaLunPanPlayReq{
			Times: 1,
		})
		if err != nil {
			t.Fatalf(`Send报错,err:%s`, err.Error())
		}
	}
	select {}
}
