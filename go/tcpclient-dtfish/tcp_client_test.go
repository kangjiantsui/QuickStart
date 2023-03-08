package tcpclient

import (
	"QuickStart/go/tcpclient-dtfish/common"
	"QuickStart/go/tcpclient-dtfish/net/codec"
	"QuickStart/go/tcpclient-dtfish/net/tcp"
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

// 创建一个session
func newSession() (*tcp.Session, uint64, error) {
	wg := sync.WaitGroup{}
	wg.Add(1)
	var uid uint64
	conn, err := net.Dial("tcp", "127.0.0.1:11000")
	if err != nil {
		return nil, 0, fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	session := tcp.NewSession(
		conn,
		tcp.SessionTypeTcp,
		tcp.NewMsgParser(),
		&codec.DTFishClientProtoProtocol{Endian_: binary.LittleEndian},
		2000,
	)
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
		return nil, 0, err
	}
	err = session.Send(&common.ProtocolClientHead{
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_PLAYER_LOGIN),
	}, &pb.PbCsPlayerLoginReqMsg{
		LoginType:       pb.EmLoginType_Login_type_dt,
		DtfishLoginData: loginData,
	})
	go func() {
		for {
			msg, _ := session.Receive()
			if msg == nil {
				continue
			}
			resp := msg.([]interface{})
			head := resp[0].(*common.ProtocolClientHead)
			uid = head.Uid_
			wg.Done()
			break
		}
	}()
	wg.Wait()
	return session, uid, err
}

func getMessageByCmd(cmd pb.EmCSMsgId) (proto.Message, error) {
	switch cmd {
	case pb.EmCSMsgId_CS_MSG_GAME_SHOP_PURCHASE:
		return &pb.PbCsGamePlayerShopPurchaseMsg{}, nil
	case pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_BUY:
		return &pb.JiJiaLunPanBuyResp{}, nil
	case pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PLAY:
		return &pb.JiJiaLunPanPlayResp{}, nil
	}
	return nil, fmt.Errorf("cmd 不支持,cmd:%d", cmd)
}

// send消息并返回pb对象
func sendAndReturnResp(session *tcp.Session, uid uint64, cmd pb.EmCSMsgId, msg proto.Message) proto.Message {
	err := send(session, uid, cmd, msg)
	if err != nil {
		panic(err)
	}
	return receive(session, cmd)
}

// 封装session.Send方法,方便调用,提升可读性
func send(session *tcp.Session, uid uint64, cmd pb.EmCSMsgId, msg proto.Message) error {
	return session.Send(&common.ProtocolClientHead{Uid_: uid, Msg_id_: uint32(cmd)}, msg)
}

func receive(session *tcp.Session, targetCmd pb.EmCSMsgId) proto.Message {
	var wg sync.WaitGroup
	wg.Add(1)
	result, err := getMessageByCmd(targetCmd)
	if err != nil {
		panic(err)
	}
	go func() {
		for {
			msg, _ := session.Receive()
			if msg == nil {
				continue
			}
			resp := msg.([]interface{})
			head := resp[0].(*common.ProtocolClientHead)
			cmd := pb.EmCSMsgId(head.Msg_id_)
			if cmd != targetCmd {
				continue
			}
			err = proto.Unmarshal(resp[1].([]uint8), result)
			if err != nil {
				panic(err)
			}
			wg.Done()
			break
		}
	}()
	wg.Wait()
	return result
}

func TestTcpClient(t *testing.T) {
	session, uid, err := newSession()
	if err != nil {
		t.Error(err)
		return
	}
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
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_SHOP_EXCHANGE_DELIVERY, &pb.PBCsGameShopExchangeDeliveryReqMsg{ProductId: 101010301, Count: 500})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 9001})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 4008})
	_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PICK, &pb.JiJiaLunPanPickReq{ItemId: 14001})
	for i := 0; i < 200; i++ {
		_ = send(session, uid, pb.EmCSMsgId_CS_MSG_GAME_JIJIALUNPAN_PLAY, &pb.JiJiaLunPanPlayReq{Times: 1})
	}
	select {}
}
