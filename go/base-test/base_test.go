package base_test

import (
	"QuickStart/go/utils"
	"encoding/json"
	"flag"
	"fmt"
	"math/rand"
	"testing"
)

func TestShuffle(t *testing.T) {
	arr := []int32{1, 2, 3, 4, 5}
	for i := 0; i < 10; i++ {
		rand.Shuffle(len(arr), func(i, j int) {
			arr[i], arr[j] = arr[j], arr[i]
		})
		t.Log(arr)
	}
}

func init() {
	flag.IntVar(&paobei, "paobei", 0, "paobei value")
}

var paobei int

func TestFlag(t *testing.T) {
	fmt.Println(paobei)
}

func TestRandSeed(t *testing.T) {
	//rand.Seed(time.Now().Unix())
	go func() {
		t.Log(utils.GetRandomList())
		t.Log(utils.GetRandomList())
		t.Log(utils.GetRandomList())
		t.Log(utils.GetRandomList())
		t.Log()
		t.Log()
	}()
	t.Log(utils.GetRandomList())
	t.Log(utils.GetRandomList())
	t.Log(utils.GetRandomList())
	t.Log(utils.GetRandomList())
}

func TestJsonM(t *testing.T) {
	s := struct {
		name string
	}{}
	s.name = "aaa"
	sJson, err := json.Marshal(s)
	if err != nil {
		return
	}
	t.Log(string(sJson))
}
