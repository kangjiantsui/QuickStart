package _go

import (
	"QuickStart/go/common"
	"QuickStart/go/net/codec"
	"QuickStart/go/net/tcp"
	"encoding/binary"
	"net"
	"testing"
)

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "10.10.3.30:14000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	session := tcp.NewSession(conn, tcp.Session_type_tcp, tcp.NewMsgParser(), &codec.ProtoClientProtocol{Endian_: binary.BigEndian}, 100)
	PrintJson(session)
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    100,
		Seq_:    100,
		Msg_id_: 1001,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
}
