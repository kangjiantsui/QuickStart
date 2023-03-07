package tcpclient

import (
	"QuickStart/go/tcpclient-dtfish/common"
	"QuickStart/go/tcpclient-dtfish/net/codec"
	tcp2 "QuickStart/go/tcpclient-dtfish/net/tcp"
	pb "QuickStart/go/tcpclient-dtfish/proto"
	dtpb "QuickStart/go/tcpclient-dtfish/proto/dtfish"
	"QuickStart/go/utils"
	"encoding/binary"
	"fmt"
	"github.com/golang/protobuf/proto"
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
			uid = resp[0].(*common.ProtocolClientHead).Uid_
			t.Log(uid)
			wg.Done()
			break
		}
	}()
	loginType := dtpb.EnumLoginType_enumLoginTypeToRegisterNewUser
	gameType := dtpb.EnumGameType_enumGameTypeDouDiZhu
	account := "asadsadsasdasdads"
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
		Uid_:    111,
		Seq_:    100,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_PLAYER_LOGIN),
	}, &pb.PbCsPlayerLoginReqMsg{
		LoginType:       pb.EmLoginType_Login_type_dt,
		DtfishLoginData: loginData,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	wg.Wait()
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    uid,
		Seq_:    100,
		Msg_id_: uint32(pb.EmCSMsgId_CS_MSG_GAME_SHOP_EXCHANGE_DELIVERY),
	}, &pb.PBCsGameShopExchangeDeliveryReqMsg{
		ProductId: 1111,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	select {}
}
