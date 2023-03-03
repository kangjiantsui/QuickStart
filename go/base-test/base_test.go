package base_test

import (
	"QuickStart/go/utils"
	"encoding/json"
	"flag"
	"fmt"
	"github.com/pkg/errors"
	"math/rand"
	"testing"
)

func TestErrWrap(t *testing.T) {
	t.Logf(`%+v`, foo())
	t.Log(foo())
}

func foo() error {
	return errors.WithStack(fmt.Errorf(`err`))
}

func TestSliceAppendNil(t *testing.T) {
	type _struct = struct {
	}
	var s []*_struct
	s = append(s, &_struct{})
	s = append(s, nil)
	s = append(s, &_struct{})
	utils.PrintJson(s)
}

func TestFloatCalc(t *testing.T) {
	var a = 0.1
	var b = 0.2
	var c = a + b
	t.Logf("%.1f + %.1f = %.17f\n", a, b, c)
}

func TestPrivateFieldBeJson(t *testing.T) {
	s := struct {
		Name        string
		privateName string `json:"private_name"`
	}{
		Name:        "Name",
		privateName: "privateName",
	}
	sJson, err := json.Marshal(s)
	if err != nil {
		panic(err.Error())
	}
	t.Log(string(sJson))
}

func TestDefer(t *testing.T) {
	defer t.Log("defer")
	panic("panic")
}

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
