package tcpclient

import (
	"QuickStart/go/tcpclient/common"
	"QuickStart/go/tcpclient/net/codec"
	tcp2 "QuickStart/go/tcpclient/net/tcp"
	"encoding/binary"
	"net"
	"testing"
)

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "10.10.3.30:14000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	session := tcp2.NewSession(conn, tcp2.Session_type_tcp, tcp2.NewMsgParser(), &codec.ProtoClientProtocol{Endian_: binary.BigEndian}, 100)
	err = session.Send(&common.ProtocolClientHead{
		Uid_:    100,
		Seq_:    100,
		Msg_id_: 100002,
	})
	if err != nil {
		t.Fatalf(`Send报错,err:%s`, err.Error())
	}
}
