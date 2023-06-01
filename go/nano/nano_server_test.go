package nano

import (
	"github.com/gorilla/websocket"
	"log"
	"testing"
)

func TestNanoServer(t *testing.T) {
	runWsServer()
	select {}
}

func TestNanoWsClient(t *testing.T) {
	url := `ws://127.0.0.1:5408/ws`
	conn, _, err := websocket.DefaultDialer.Dial(url, nil)
	if err != nil {
		log.Fatal(err)
	}
	err = conn.WriteMessage(websocket.BinaryMessage, nil)
	if err != nil {
		panic(err)
	}
	select {}
}
