import struct


def read_byte(data):
    return data[0], data[1:]


def read_int(data):
    value, = struct.unpack('>I', data[:4])
    return value, data[4:]


def read_float(data):
    value, = struct.unpack('>f', data[:4])
    return value, data[4:]


def read_string(data):
    # 读取字符串长度
    length, data = read_int(data)
    # 读取字符串
    value = data[:length].decode('utf-8')
    return value, data[length:]


def write_int(buf, value, optimize_positive=True):
    if not optimize_positive:
        value = value << 1 ^ value >> 31

    bytes_list = []
    while True:
        b = value & 0x7F
        value >>= 7
        if value == 0:
            bytes_list.append(b)
            break
        bytes_list.append(b | 0x80)
        if value == 0:
            break

    return buf + bytes(bytearray(bytes_list))


def write_string(buf, value):
    if value is None:
        return buf + b'\x80'
    char_count = len(value)
    if char_count == 0:
        return buf + b'\x81'
    if 1 < char_count < 64 and all(ord(c) <= 127 for c in value):
        ascii_encoded = value.encode('ascii')
        ascii_encoded = ascii_encoded[:-1] + bytes([ascii_encoded[-1] | 128])
        return buf + ascii_encoded
    else:
        utf8_encoded = value.encode('utf-8')
        length = len(utf8_encoded) + 1
        return write_int(buf, length) + utf8_encoded


def parse_kryo_object(data):
    # 假设我们的对象以整数字段开始
    int_field, data = read_int(data)

    # 接着是一个浮点字段
    float_field, data = read_float(data)

    # 接着是一个字符串字段，读取字符串时首先读取长度
    string_field, data = read_string(data)

    # 构造并返回对象
    obj = {
        'int_field': int_field,
        'float_field': float_field,
        'string_field': string_field
    }
    return obj, data
