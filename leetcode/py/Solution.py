import unittest
from typing import List, Optional


def two_sum(nums: List[int], target: int) -> List[int]:
    seen = {}  # 创建一个空字典来存储访问过的元素及其索引
    for index, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], index]  # 如果找到 complement，则返回其索引与当前索引
        seen[num] = index  # 将当前元素及其索引保存到字典中
    return []  # 如果没有找到符合条件的元素，返回空列表


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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
    head = None  # 初始化结果链表的头节点
    tail = None  # 初始化结果链表的尾节点
    carry = 0  # 初始化进位，用于存储相加时产生的进位

    # 当 l1 或 l2 至少有一个不为 None 时，继续循环
    while l1 is not None or l2 is not None:
        n1 = l1.val if l1 is not None else 0  # 获取 l1 的当前值，如果 l1 为 None，则使用 0
        n2 = l2.val if l2 is not None else 0  # 获取 l2 的当前值，如果 l2 为 None，则使用 0
        sum = n1 + n2 + carry  # 计算当前位的总和，包括进位
        carry = sum // 10  # 计算新的进位
        sum = sum % 10  # 计算当前位的值

        new_node = ListNode(val=sum)  # 创建新节点存储当前位的值
        if head is None:  # 如果头节点为 None，初始化链表
            head = new_node
            tail = new_node
        else:  # 否则，将新节点添加到尾部
            tail.next = new_node
            tail = new_node

        if l1 is not None:  # 如果 l1 不为 None，移动到下一个节点
            l1 = l1.next
        if l2 is not None:  # 如果 l2 不为 None，移动到下一个节点
            l2 = l2.next

    if carry > 0:  # 如果最后还有进位，添加到链表的末尾
        tail.next = ListNode(val=carry)

    return head  # 返回结果链表的头节点


def palindrome_number(x: int) -> bool:
    x_str = str(x)
    x_str_reversed = x_str[::-1]
    return x_str == x_str_reversed


class Test(unittest.TestCase):
    def test_two_sum(self):
        self.assertEqual(two_sum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(two_sum([3, 2, 4], 6), [1, 2])
        self.assertEqual(two_sum([3, 3], 6), [0, 1])
        self.assertEqual(two_sum([1, 2, 3], 5), [1, 2])
        self.assertEqual(two_sum([5, 5], 10), [0, 1])
        self.assertEqual(two_sum([], 1), [])

    def test_add_two_numbers(self):
        li = ListNode.from_values(2, 4, 3)
        l2 = ListNode.from_values(5, 6, 4)

        print(li.get_list())
        self.assertEqual(add_two_numbers(li, l2).get_list(), [7, 0, 8])

    def test_get_list(self):
        l1 = ListNode.from_values(2, 4, 3)
        self.assertEqual(l1.get_list(), [2, 4, 3])
        l2 = ListNode.from_values(5, 6, 4)
        self.assertEqual(l2.get_list(), [5, 6, 4])
        l3 = ListNode.from_values(7, 0, 8)
        self.assertEqual(l3.get_list(), [7, 0, 8])

    def test_palindrome_number(self):
        self.assertEqual(palindrome_number(121), True)
        self.assertEqual(palindrome_number(-121), False)
        self.assertEqual(palindrome_number(10), False)
        self.assertEqual(palindrome_number(-101), False)

    def test_math(self):
        print(10 ** 3)
