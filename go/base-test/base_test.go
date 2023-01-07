package base_test

import (
	"flag"
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

var cmdLocal = flag.Bool("local", false, "run local info: OnlineSvrInfo")

func TestFlag(t *testing.T) {
	t.Log(*cmdLocal)
}
