# https://leetcode.com/problems/search-insert-position/description/
# Example 1:
# Input: nums = [1,3,5,6], target = 5
# Output: 2
import unittest
# Example 2:
# Input: nums = [1,3,5,6], target = 2
# Output: 1

# Example 3:
# Input: nums = [1,3,5,6], target = 7
# Output: 4

from typing import List


# 二分查找
def search_insert(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (right + left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return left


class Test(unittest.TestCase):
    def test_two_sum(self):
        self.assertEqual(search_insert([1, 3, 5, 6], 5), 2)
        self.assertEqual(search_insert([1, 3, 5, 6], 2), 1)
        self.assertEqual(search_insert([1, 3, 5, 6], 7), 4)
