package main

import (
	"QuickStart/go/utils"
	"fmt"
)

// 避免使用go test无法暴露所有问题,搞个main做一些测试
func main() {
	fmt.Println(utils.GetRandomList())
	fmt.Println(utils.GetRandomList())
	fmt.Println(utils.GetRandomList())

	go func() {
		fmt.Println(utils.GetRandomList())
		fmt.Println(utils.GetRandomList())
		fmt.Println(utils.GetRandomList())
	}()

	go func() {
		fmt.Println(utils.GetRandomList())
		fmt.Println(utils.GetRandomList())
		fmt.Println(utils.GetRandomList())
	}()
}
