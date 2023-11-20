import wmi
from screeninfo import get_monitors

c = wmi.WMI()

# 内存条信息
for memory in c.Win32_PhysicalMemory():
    print(f"内存条容量: {int(memory.Capacity) / (1024 ** 3)} GB")
    print(f"内存条速度: {memory.Speed} MHz")
    print(f"内存条制造商: {memory.Manufacturer}")
    print()

# 内存条插槽信息
for memory_array in c.Win32_PhysicalMemoryArray():
    print(f"内存条插槽总数量: {memory_array.MemoryDevices}")
    print()

# 主板信息
for board in c.Win32_BaseBoard():
    print(f"主板型号: {board.Product}")
    print()

# 硬盘信息
for disk_drive in c.Win32_DiskDrive():
    print(f"硬盘型号: {disk_drive.Model}")
    print(f"硬盘类型: {disk_drive.MediaType}")
    print(f"硬盘容量: {int(disk_drive.Size) / (1024 ** 3)} GB")
    print(f"硬盘分区数量: {disk_drive.Partitions}")
    print()


for monitor in get_monitors():
    print(f"Name: {monitor.name}")
    print(f"Width: {monitor.width}, Height: {monitor.height}")
