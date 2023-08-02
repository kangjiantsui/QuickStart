:: 这个脚本用于自动终止占用8080端口的进程。
:: 它首先找到使用8080端口的进程的PID。
:: 然后它使用taskkill命令强制终止找到的PID的进程。
@echo off
for /f "tokens=5" %%a in ('netstat -ano ^| findstr "8080"') do (
taskkill /pid %%a /f
)
echo The process using port 8080 has been terminated.
pause