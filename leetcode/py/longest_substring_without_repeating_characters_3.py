# 题目描述
# 这道题目叫做 "Longest Substring Without Repeating Characters"（最长不重复子串）。题目要求给定一个字符串 s，找出其中不含有重复字符的最长子串的长度。
#
# 示例：
# 示例 1：
# 输入：s = "abcabcbb"
# 输出：3
# 解释：答案是 "abc"，长度为 3。
#
# 示例 2：
# 输入：s = "bbbbb"
# 输出：1
# 解释：答案是 "b"，长度为 1。
#
# 示例 3：
# 输入：s = "pwwkew"
# 输出：3
# 解释：答案是 "wke"，长度为 3。
#
# 约束条件：
# 字符串 s 的长度在 0 到 5 * 10^4 之间。
# 字符串 s 由英文字母、数字、符号和空格组成。
# Python 解法和解题思路
# 这道题可以使用滑动窗口的方法来解决。具体步骤如下：
#
# 初始化两个指针：start = 0 和 end = 0，以及一个用于存储字符最后出现位置的字典 last_occurrence。
# 遍历字符串：使用 end 指针遍历字符串。
# 更新窗口：如果 end 指针指向的字符已经在 last_occurrence 字典中，更新 start 指针为 last_occurrence[s[end]] + 1 和 start 的较大值。
# 更新结果：每次遍历时，更新最长子串的长度。
# 更新字符最后出现的位置：将 end 指针指向的字符的最后出现位置更新为 end。
import unittest


def length_of_longest_substring(s: str) -> int:
    start = 0
    max_len = 0
    last_occurrence = {}

    for end in range(len(s)):
        if s[end] in last_occurrence:
            start = max(start, last_occurrence[s[end]] + 1)

        max_len = max(max_len, end - start + 1)

        last_occurrence[s[end]] = end

    return max_len


class Test(unittest.TestCase):

    def test_length_of_longest_substring(self):
        self.assertEqual(length_of_longest_substring("abcabcbb"), 3)
        self.assertEqual(length_of_longest_substring("bbbbb"), 1)
        self.assertEqual(length_of_longest_substring("pwwkew"), 3)
        self.assertEqual(length_of_longest_substring(""), 0)
        self.assertEqual(length_of_longest_substring(" "), 1)
        self.assertEqual(length_of_longest_substring("au"), 2)
        self.assertEqual(length_of_longest_substring("dvdf"), 3)
