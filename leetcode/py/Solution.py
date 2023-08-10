import unittest
from typing import List


def two_sum(nums: List[int], target: int) -> List[int]:
    seen = {}  # 创建一个空字典来存储访问过的元素及其索引
    for index, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], index]  # 如果找到 complement，则返回其索引与当前索引
        seen[num] = index  # 将当前元素及其索引保存到字典中
    return []  # 如果没有找到符合条件的元素，返回空列表


class Test(unittest.TestCase):
    def test_two_sum(self):
        self.assertEqual(two_sum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(two_sum([3, 2, 4], 6), [1, 2])
        self.assertEqual(two_sum([3, 3], 6), [0, 1])
        self.assertEqual(two_sum([1, 2, 3], 5), [1, 2])
        self.assertEqual(two_sum([5, 5], 10), [0, 1])
        self.assertEqual(two_sum([], 1), [])
