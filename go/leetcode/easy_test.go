package leetcode

import "testing"

func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}

func TestTwoSum(t *testing.T) {
	result := twoSum([]int{2, 7, 11, 15}, 9)
	t.Log(result)
}
