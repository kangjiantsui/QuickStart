package _go

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
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
