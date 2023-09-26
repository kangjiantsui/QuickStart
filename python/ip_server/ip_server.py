from datetime import datetime

from flask import Flask, request

app = Flask(__name__)


def get_last_record():
    try:
        with open('ip_record', 'r') as f:
            lines = f.readlines()
            if lines:
                return lines[-1].strip()
    except FileNotFoundError:
        return None
    return None


@app.route('/report', methods=['GET'])
def report_ip():
    client_ip = request.headers.get('X-Real-IP', request.remote_addr)
    print(client_ip)
    # 获取当前时间戳
    timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    last_record = get_last_record()

    if last_record:
        last_ip = last_record.rsplit(' ', 1)[-1]
    else:
        last_ip = None

    from_home = request.args.get('from_home', None)
    if from_home == 'true' and client_ip != last_ip:
        # IP地址变更，记录到文件
        with open('ip_record', 'a') as f:
            f.write(f"{timestamp} {client_ip}\n")
    return client_ip


@app.route('/query', methods=['GET'])
def query_ip():
    # 从文件 `ip_record` 中读取 IP
    last_record = get_last_record()
    if last_record:
        return last_record
    else:
        return "No IP record found."


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8081)
