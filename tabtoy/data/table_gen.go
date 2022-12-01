// Generated by github.com/davyxu/tabtoy
// DO NOT EDIT!!
// Version: 3.1.4
package data

import "errors"

type TableEnumValue struct {
	Name  string
	Index int32
}

type Atype int32

const (
	Atype_NewYearCrazy = 16 // 新春狂欢
)

var (
	AtypeEnumValues = []TableEnumValue{
		{Name: "NewYearCrazy", Index: 16}, // 新春狂欢
	}
	AtypeMapperValueByName = map[string]int32{}
	AtypeMapperNameByValue = map[int32]string{}
)

func (self Atype) String() string {
	name, _ := AtypeMapperNameByValue[int32(self)]
	return name
}

type ActivityConfig struct {
	ActivityID   int32  `tb_name:"活动ID"`
	AType        Atype  `tb_name:"活动类型"`
	BeginTime    int32  `tb_name:"开始时间"`
	EndTime      int32  `tb_name:"结束时间"`
	Name         string `tb_name:"名称"`
	CompleteShow bool   `tb_name:"完成后显示"`
}

type MyData struct {
	ID   int32  `tb_name:"ID"`
	Name string `tb_name:"名称"`
}

type BaseConfig struct {
	ServerIP string `tb_name:"服务器IP"`
}

// Combine struct
type Table struct {
	ActivityConfig []*ActivityConfig // table: ActivityConfig
	MyData         []*MyData         // table: MyData
	BaseConfig     []*BaseConfig     // table: BaseConfig

	// Indices
	ActivityConfigByActivityID map[int32]*ActivityConfig `json:"-"` // table: ActivityConfig

	// Handlers
	postHandlers []func(*Table) error `json:"-"`
	preHandlers  []func(*Table) error `json:"-"`

	indexHandler map[string]func() `json:"-"`
	resetHandler map[string]func() `json:"-"`
}

// table: BaseConfig
func (self *Table) GetKeyValue_BaseConfig() *BaseConfig {
	return self.BaseConfig[0]
}

// 注册加载后回调(用于构建数据)
func (self *Table) RegisterPostEntry(h func(*Table) error) {

	if h == nil {
		panic("empty postload handler")
	}

	self.postHandlers = append(self.postHandlers, h)
}

// 注册加载前回调(用于清除数据)
func (self *Table) RegisterPreEntry(h func(*Table) error) {

	if h == nil {
		panic("empty preload handler")
	}

	self.preHandlers = append(self.preHandlers, h)
}

// 清除索引和数据
func (self *Table) ResetData() error {

	err := self.InvokePreHandler()
	if err != nil {
		return err
	}

	return self.ResetTable("")
}

// 全局表构建索引及通知回调
func (self *Table) BuildData() error {

	err := self.IndexTable("")
	if err != nil {
		return err
	}

	return self.InvokePostHandler()
}

// 调用加载前回调
func (self *Table) InvokePreHandler() error {
	for _, h := range self.preHandlers {
		if err := h(self); err != nil {
			return err
		}
	}

	return nil
}

// 调用加载后回调
func (self *Table) InvokePostHandler() error {
	for _, h := range self.postHandlers {
		if err := h(self); err != nil {
			return err
		}
	}

	return nil
}

// 为表建立索引. 表名为空时, 构建所有表索引
func (self *Table) IndexTable(tableName string) error {

	if tableName == "" {

		for _, h := range self.indexHandler {
			h()
		}
		return nil

	} else {
		if h, ok := self.indexHandler[tableName]; ok {
			h()
		}

		return nil
	}
}

// 重置表格数据
func (self *Table) ResetTable(tableName string) error {
	if tableName == "" {
		for _, h := range self.resetHandler {
			h()
		}

		return nil
	} else {
		if h, ok := self.resetHandler[tableName]; ok {
			h()
			return nil
		}

		return errors.New("reset table failed, table not found: " + tableName)
	}
}

// 初始化表实例
func NewTable() *Table {

	self := &Table{
		indexHandler: make(map[string]func()),
		resetHandler: make(map[string]func()),
	}

	self.indexHandler["ActivityConfig"] = func() {

		for _, v := range self.ActivityConfig {
			self.ActivityConfigByActivityID[v.ActivityID] = v
		}
	}

	self.indexHandler["MyData"] = func() {

	}

	self.indexHandler["BaseConfig"] = func() {

	}

	self.resetHandler["ActivityConfig"] = func() {
		self.ActivityConfig = nil

		self.ActivityConfigByActivityID = map[int32]*ActivityConfig{}
	}
	self.resetHandler["MyData"] = func() {
		self.MyData = nil

	}
	self.resetHandler["BaseConfig"] = func() {
		self.BaseConfig = nil

	}

	self.ResetData()

	return self
}

func init() {

	for _, v := range AtypeEnumValues {
		AtypeMapperValueByName[v.Name] = v.Index
		AtypeMapperNameByValue[v.Index] = v.Name
	}

}
