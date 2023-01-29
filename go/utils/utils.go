package utils

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"os"
)

func PrintJson(obj interface{}) {
	res, err := json.Marshal(obj)
	if err != nil {
		log.Fatal(err.Error())
	}
	var out bytes.Buffer
	err = json.Indent(&out, res, "", "\t")
	_, err = out.WriteTo(os.Stdout)
	if err != nil {
		log.Fatal(err.Error())
	}
	fmt.Println()
	fmt.Println(`-----------------------------------------------------------------------------------------------------`)
}

func GetRandomList() []int32 {
	var result []int32
	for i := 0; i < 10; i++ {
		result = append(result, rand.Int31n(10))
	}
	return result
}
