from urllib.parse import unquote

encoded_str = "2Fcdc5736389a66fdd19206214a9b76977"
decoded_str = unquote(encoded_str)
print(decoded_str)  # 输出：Enabled/cdc5736389a66fdd19206214a9b76977
