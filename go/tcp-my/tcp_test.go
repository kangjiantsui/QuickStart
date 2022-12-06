package tcp_my

import (
	"net"
	"testing"
)

func TestTcpClient(t *testing.T) {
	conn, err := net.Dial("tcp", "127.0.0.1:9909")
	if err != nil {
		t.Fatal(err)
	}
	_, err = conn.Write([]byte(`test`))
	if err != nil {
		t.Fatal(err)
	}
	err = conn.Close()
	if err != nil {
		t.Fatal(err)
	}

}

func TestTcpServer(t *testing.T) {
	listener, err := net.Listen("tcp", "127.0.0.1:9909")
	if err != nil {
		t.Fatal(err)
	}
	defer func() {
		err = listener.Close()
		if err != nil {
			t.Fatal(err)
		}
	}()
	t.Logf(`绑定端口,%q`, listener.Addr())
	for {
		conn, err := listener.Accept()
		if err != nil {
			t.Fatal(err)
		}
		go func(c net.Conn) {
			defer func(c net.Conn) {
				err := c.Close()
				if err != nil {
					t.Error(err)
					return
				}
			}(c)
			t.Log(`收到请求`)
			var buf [1024]byte
			for {
				n, err := c.Read(buf[:])
				if err != nil {
					t.Error(err)
					return
				}
				t.Logf("recv from client,content:%s\n", string(buf[:n]))
			}
		}(conn)
	}
}
