package base_test

import (
	"flag"
	"fmt"
	"math/rand"
	"testing"
	"time"
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

func getRandomList() []int32 {
	var result []int32
	for i := 0; i < 10; i++ {
		result = append(result, rand.Int31n(10))
	}
	return result
}

func TestRandSeed(t *testing.T) {
	rand.Seed(time.Now().Unix())
	t.Log(getRandomList())
	t.Log(getRandomList())
	t.Log(getRandomList())
	t.Log(getRandomList())
}
