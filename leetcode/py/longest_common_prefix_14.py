import unittest
from typing import List


def longest_common_prefix(strs: List[str]) -> str:
    prefix = strs[0]
    for string in strs[1:]:
        i = 0
        while i < len(prefix) and i < len(string) and prefix[i] == string[i]:
            i += 1
        prefix = prefix[:i]
    return prefix


class Test(unittest.TestCase):

    def test_add_two_numbers(self):
        self.assertEqual(longest_common_prefix(["flower", "flow", "flight"]), "fl")
