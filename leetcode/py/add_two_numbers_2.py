# https://leetcode.com/problems/add-two-numbers/
import unittest
from typing import Optional, List


# noinspection DuplicatedCode
class ListNode:
    def __init__(self, val=0, next_node=None):
        self.val = val
        self.next = next_node

    @classmethod
    def from_values(cls, *values):
        head = None
        tail = None
        for value in values:
            new_node = cls(val=value)
            if head is None:
                head = new_node
                tail = new_node
            else:
                tail.next = new_node
                tail = new_node
        return head

    def get_list(self) -> List[int]:
        result = []
        node = self
        while node is not None:
            result.append(node.val)
            node = node.next
        return result


def add_two_numbers(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    head = None
    tail = None
    carry = 0

    while l1 is not None or l2 is not None:
        n1 = l1.val if l1 is not None else 0
        n2 = l2.val if l2 is not None else 0

        sum_val = n1 + n2 + carry
        carry = sum_val // 10
        val = sum_val % 10

        new_node = ListNode(val)
        if head is None:
            head = new_node
            tail = new_node
        else:
            tail.next = new_node
            tail = new_node

        if l1 is not None:
            l1 = l1.next
        if l2 is not None:
            l2 = l2.next

    if carry > 0:
        tail.next = ListNode(carry)

    return head


class Test(unittest.TestCase):

    def test_add_two_numbers(self):
        li = ListNode.from_values(2, 4, 3)
        l2 = ListNode.from_values(5, 6, 4)

        print(li.get_list())
        self.assertEqual(add_two_numbers(li, l2).get_list(), [7, 0, 8])
