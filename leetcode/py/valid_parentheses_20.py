# https://leetcode.com/problems/valid-parentheses/
import unittest


# Example 1:
# Input: s = "()"
# Output: true

# Example 2:
# Input: s = "[()[]{}]"
# Output: true

# Example 3:
# Input: s = "(]"
# Output: false

def is_valid(s: str) -> bool:
    mapping = {"(": ")", "[": "]", "{": "}"}
    stack = []
    for char in s:
        if char in mapping.keys():
            stack.append(char)
        elif len(stack) == 0:
            return False
        elif char != mapping[stack.pop()]:
            return False
    return len(stack) == 0


class Test(unittest.TestCase):

    def test_is_valid(self):
        self.assertEqual(is_valid("]"), False)
        self.assertEqual(is_valid("(]"), False)
        self.assertEqual(is_valid("()"), True)
        self.assertEqual(is_valid("[()[]{}]"), True)
        self.assertEqual(is_valid("(("), False)
