package nano

import (
	"fmt"
	"github.com/lonng/nano"
	"github.com/lonng/nano/serialize/msgpack"
	"log"
	"net/http"
	"strings"
	"time"

	"github.com/lonng/nano/component"
	"github.com/lonng/nano/session"
)

// 自定义组件
type CustomComponent struct {
	component.Base
}

func (c *CustomComponent) AfterInit() {
	log.Println("CustomComponent initialized")
}

func (c *CustomComponent) SayHello(s *session.Session, msg []byte) error {
	log.Println("Received message:", string(msg))
	return s.Response("Hello, client!")
}

func runWsServer() {
	go func() {
		components := &component.Components{}
		components.Register(
			&CustomComponent{},
			component.WithName("blood"), // rewrite component and handler name
			component.WithNameFunc(strings.ToLower),
		)
		nano.Listen(fmt.Sprintf(":%d", 5408),
			nano.WithDebugMode(),
			nano.WithIsWebsocket(true),
			nano.WithCheckOriginFunc(func(_ *http.Request) bool { return true }),
			nano.WithWSPath("/ws"),
			nano.WithHeartbeatInterval(30*time.Minute),
			nano.WithComponents(components),
			nano.WithSerializer(msgpack.NewSerializer()),
		)
	}()
}
