# 两数之和,https://leetcode.com/problems/two-sum/
import unittest
from typing import List


# Example 1:
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Example 2:
# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Example 3:
# Input: nums = [3,3], target = 6
# Output: [0,1]


def two_sum(nums: List[int], target: int) -> List[int]:
    seen = {}
    for index, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], index]
        seen[num] = index
    return []


def two_sum1(nums: List[int], target: int) -> List[int]:
    nums_with_index = [(num, index) for index, num in enumerate(nums)]
    nums_with_index.sort()  # 对数组进行排序，同时保留原始索引

    left, right = 0, len(nums) - 1  # 初始化两个指针，一个指向数组的开始，一个指向数组的末尾

    while left < right:
        current_sum = nums_with_index[left][0] + nums_with_index[right][0]
        if current_sum == target:
            return [nums_with_index[left][1], nums_with_index[right][1]]  # 返回原始索引
        elif current_sum < target:
            left += 1  # 如果当前和小于目标值，移动左指针
        else:
            right -= 1  # 如果当前和大于目标值，移动右指针

    return []  # 如果没有找到符合条件的元素，返回空列表


class Test(unittest.TestCase):
    # noinspection DuplicatedCode
    def test_two_sum(self):
        self.assertEqual(two_sum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(two_sum([3, 2, 4], 6), [1, 2])
        self.assertEqual(two_sum([3, 3], 6), [0, 1])
        self.assertEqual(two_sum([1, 2, 3], 5), [1, 2])
        self.assertEqual(two_sum([5, 5], 10), [0, 1])
        self.assertEqual(two_sum([], 1), [])

    def test_two_sum1(self):
        self.assertEqual(two_sum1([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(two_sum1([3, 2, 4], 6), [1, 2])
        self.assertEqual(two_sum1([3, 3], 6), [0, 1])
        self.assertEqual(two_sum1([1, 2, 3], 5), [1, 2])
        self.assertEqual(two_sum1([5, 5], 10), [0, 1])
        self.assertEqual(two_sum1([], 1), [])
