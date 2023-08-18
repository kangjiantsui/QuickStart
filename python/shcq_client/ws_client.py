import asyncio
import struct
import unittest

import websockets

from python.shcq_client.codec.codec import write_string, write_int


async def send_message(websocket):
    message = {
        'loginName': 'test_user',
        'sid': 100,
        'pid': 200,
        'client': 1,
        'idNumber': '123456789',
        'ip': '192.168.1.1',
        'version': 1,
        'channelId': 'channel_1',
        'qudao': 'qudao_1',
        'isAdult': 0,
        'token': 'token_123'
    }
    payload = encode_req_login_message(message)
    # 计算长度字段，包括长度字段本身（4字节），消息ID（4字节），序列号（2字节）和有效负载长度
    length = 4 + 4 + 2 + len(payload)
    # 创建一个字节缓冲区并使用 struct 打包
    buffer = struct.pack(">I I H", length, 1001, 0) + payload
    await websocket.send(buffer)


async def connect_to_server():
    uri = "ws://localhost:9101"
    async with websockets.connect(uri) as websocket:
        # 示例：发送消息ID为1，序列号为0，有效负载为 b"Hello, Server!"的消息
        await send_message(websocket)
        # response = await websocket.recv()
        # 处理响应...


def encode_req_login_message(message):
    buf = b''
    buf = write_string(buf, message['loginName'])
    buf = write_int(buf, message['sid'])
    buf = write_int(buf, message['pid'])
    buf = write_int(buf, message['client'])
    buf = write_string(buf, message['idNumber'])
    buf = write_string(buf, message['ip'])
    buf = write_int(buf, message['version'])
    buf = write_string(buf, message['channelId'])
    buf = write_string(buf, message['qudao'])
    buf = write_int(buf, message['isAdult'])
    buf = write_string(buf, message['token'])
    return buf


class Test(unittest.TestCase):
    def test_connect_to_server(self):
        asyncio.get_event_loop().run_until_complete(connect_to_server())

    def test_encode_req_login_message(self):
        # ReqLoginMessage
        message = {
            'loginName': 'test_user',
            'sid': 100,
            'pid': 200,
            'client': 1,
            'idNumber': '123456789',
            'ip': '192.168.1.1',
            'version': 1,
            'channelId': 'channel_1',
            'qudao': 'qudao_1',
            'isAdult': 0,
            'token': 'token_123'
        }

        encoded_message = encode_req_login_message(message)
        print(encoded_message)
