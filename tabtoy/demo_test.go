package table

import (
	"QuickStart/go/utils"
	"QuickStart/tabtoy/data"
	"fmt"
	tabtoy "github.com/davyxu/tabtoy/v3/api/golang"
	"os"
	"testing"
)

var Tab *data.Table

func init() {
	loadAllTable()
}

// 一次性加载所有表
func loadAllTable() {
	Tab = data.NewTable()
	// 表加载前清除之前的手动索引和表关联数据
	Tab.RegisterPreEntry(func(tab *data.Table) error {
		fmt.Println("tab pre load clear")
		return nil
	})
	// 表加载和构建索引后，需要手动处理数据的回调
	Tab.RegisterPostEntry(func(tab *data.Table) error {
		fmt.Println("tab post load done")
		return nil
	})
	err := tabtoy.LoadFromFile(Tab, "./data/table_gen.json")
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
	fmt.Println("")
}

func TestShowTableData(t *testing.T) {
	utils.PrintJson(Tab.ActivityConfig)
}

func TestEnum(t *testing.T) {

}
