package table

import (
	_go "QuickStart/go"
	"fmt"
	tabtoy "github.com/davyxu/tabtoy/v3/api/golang"
	"os"
	"testing"
)

var Tab *Table

func init() {
	loadAllTable()
}

// 一次性加载所有表
func loadAllTable() {
	Tab = NewTable()
	// 表加载前清除之前的手动索引和表关联数据
	Tab.RegisterPreEntry(func(tab *Table) error {
		fmt.Println("tab pre load clear")
		return nil
	})
	// 表加载和构建索引后，需要手动处理数据的回调
	Tab.RegisterPostEntry(func(tab *Table) error {
		fmt.Println("tab post load done")
		return nil
	})
	err := tabtoy.LoadFromFile(Tab, "table_gen.json")
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	fmt.Println("")
}

func TestShowTableData(t *testing.T) {
	_go.PrintJson(Tab.MyData)
}
