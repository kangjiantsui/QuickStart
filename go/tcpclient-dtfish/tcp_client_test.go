package tcpclient

import (
	"QuickStart/go/tcpclient-dtfish/common"
	"QuickStart/go/tcpclient-dtfish/net/codec"
	tcp2 "QuickStart/go/tcpclient-dtfish/net/tcp"
	ProtoMsg "QuickStart/go/tcpclient-dtfish/proto"
	"QuickStart/go/utils"
	"encoding/binary"
	"fmt"
	"net"
	"testing"
)

func tcpClientConn() error {
	conn, err := net.Dial("tcp", "10.10.3.30:11000")
	if err != nil {
		return fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	utils.PrintJson(conn.LocalAddr())
	_, err = conn.Write([]byte{1, 2, 3, 4, 5})
	if err != nil {
		return fmt.Errorf(`dial报错,err:%s`, err.Error())
	}
	return nil
}

func TestTcpClientConn(t *testing.T) {
	err := tcpClientConn()
	if err != nil {
		t.Fatal(err.Error())
	}
}

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "10.10.3.30:11000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	utils.PrintJson(conn.LocalAddr())
	session := tcp2.NewSession(conn, tcp2.Session_type_tcp, tcp2.NewMsgParser(), &codec.ProtoClientProtocol{Endian_: binary.LittleEndian}, int(ProtoMsg.EmCSMsgId_CS_MSG_PLAYER_LOGIN))
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    111,
		Seq_:    100,
		Msg_id_: 100002,
	}, &ProtoMsg.PbCsPlayerLoginReqMsg{LoginType: ProtoMsg.EmLoginType_Login_type_dt})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
}
