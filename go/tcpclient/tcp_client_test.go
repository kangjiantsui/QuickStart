package tcpclient

import (
	"QuickStart/go/tcpclient/common"
	"QuickStart/go/tcpclient/net/codec"
	tcp2 "QuickStart/go/tcpclient/net/tcp"
	ProtoMsg "QuickStart/go/tcpclient/proto"
	"QuickStart/go/utils"
	"encoding/binary"
	"net"
	"testing"
	"time"
)

func TestTcpClientConn(t *testing.T) {
	conn, err := net.Dial("tcp", "127.0.0.1:14000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	utils.PrintJson(conn)
}

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "10.10.3.30:11000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	session := tcp2.NewSession(conn, tcp2.Session_type_tcp, tcp2.NewMsgParser(), &codec.ProtoClientProtocol{Endian_: binary.LittleEndian}, 10000)
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    111,
		Seq_:    100,
		Msg_id_: 100002,
	}, &ProtoMsg.PbCsPlayerLoginReqMsg{LoginType: ProtoMsg.EmLoginType_Login_type_dt})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
	time.Sleep(time.Second * 2)
}
