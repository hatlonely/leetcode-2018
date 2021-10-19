package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func twoSum(nums []int, target int) []int {
	numIdx := map[int]int{}
	for idx, num := range nums {
		if i, ok := numIdx[target-num]; ok {
			return []int{i, idx}
		}
		numIdx[num] = idx
	}
	return nil
}

func Test1(t *testing.T) {
	Convey("two sum", t, func() {
		So(twoSum([]int{2, 7, 11, 15}, 9), ShouldResemble, []int{0, 1})
		So(twoSum([]int{3, 2, 4}, 6), ShouldResemble, []int{1, 2})
		So(twoSum([]int{3, 3}, 6), ShouldResemble, []int{0, 1})
	})
}
