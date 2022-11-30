package _go

import (
	"net"
	"testing"
)

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "10.10.3.30:14000")
	if err != nil {
		t.Fatalf(`dial报错,err:%s`, err.Error())
	}
	PrintJson(conn)

}
