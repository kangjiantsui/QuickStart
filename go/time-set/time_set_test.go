package time_set

import (
	"github.com/gogf/gf/os/glog"
	"github.com/gogf/gf/os/gproc"
	"github.com/gogf/gf/text/gstr"
	"runtime"
	"testing"
)

func TestUpdateSystemDate(t *testing.T) {
	UpdateSystemDate("2023-12-20 15:02:41.372")
}

func UpdateSystemDate(dateTime string) bool {
	system := runtime.GOOS
	switch system {
	case "windows":
		{
			_, err1 := gproc.ShellExec(`date  ` + gstr.Split(dateTime, " ")[0])
			_, err2 := gproc.ShellExec(`time  ` + gstr.Split(dateTime, " ")[1])
			if err1 != nil && err2 != nil {
				glog.Info("更新系统时间错误:请用管理员身份启动程序!")
				return false
			}
			return true
		}
	case "linux":
		{
			_, err1 := gproc.ShellExec(`date -s  "` + dateTime + `"`)
			if err1 != nil {
				glog.Info("更新系统时间错误:", err1.Error())
				return false
			}
			return true
		}
	case "darwin":
		{
			_, err1 := gproc.ShellExec(`date -s  "` + dateTime + `"`)
			if err1 != nil {
				glog.Info("更新系统时间错误:", err1.Error())
				return false
			}
			return true
		}
	}
	return false
}
