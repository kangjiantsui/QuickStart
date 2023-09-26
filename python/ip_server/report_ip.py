import requests
import time

while True:
    try:
        # 发送 GET 请求
        response = requests.get("http://118.89.116.224/ip/report", params={"from_home": "true"})

        # 检查请求是否成功
        if response.status_code == 200:
            print(f"Success: {response.text}")
        else:
            print(f"Failed: {response.status_code}")

    except Exception as e:
        # 输出任何引发的异常
        print(f"An error occurred: {e}")

    # 等待 60 秒
    time.sleep(60)
