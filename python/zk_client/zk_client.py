import json
import logging

from kazoo.client import KazooClient


def get_node_data(zk, path):
    """递归获取节点数据和子节点，返回字典形式的数据结构。"""
    node_data = {}

    if zk.exists(path):
        data, _ = zk.get(path)
        node_data['data'] = data.decode('utf-8') if data else 'No data'

        children = zk.get_children(path)
        if children:
            node_data['children'] = {}
            for child in children:
                # 构建子节点的完整路径
                child_path = f"{path}/{child}" if path != "/" else f"/{child}"
                node_data['children'][child] = get_node_data(zk, child_path)

    return node_data


# 设置日志级别
logging.basicConfig()

# ZooKeeper 服务器地址
zk_server = "127.0.0.1:2181"

# 创建 KazooClient 实例
zk = KazooClient(hosts=zk_server)
zk.start()

# 从根节点获取数据
zookeeper_data = get_node_data(zk, "/")

# 关闭连接
zk.stop()

# 生成 JSON 文件，文件名包含 IP 和端口，使用 LF 作为换行符
json_file_path = f"{zk_server.replace(':', '_')}.json"
with open(json_file_path, 'w', newline='\n') as file:
    json.dump(zookeeper_data, file, indent=4, separators=(',', ': '))

print(f"JSON file saved at: {json_file_path}")
