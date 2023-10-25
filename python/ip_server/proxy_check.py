import subprocess


def check_tun_mode():
    # 运行ipconfig命令并获取输出
    result = subprocess.run(['ipconfig'], stdout=subprocess.PIPE, text=True,
                            encoding='gbk')  # 使用GBK编码，因为Windows的ipconfig通常使用这种编码
    output = result.stdout

    # 搜索特定的网络适配器或IP地址
    if "未知适配器 Clash" in output and "198.18.0.1" in output:
        return True
    return False


# 检查是否启用了TUN模式
if check_tun_mode():
    print("TUN模式已启用。")
else:
    print("TUN模式未启用。")



