package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func findMin(nums []int) int {
	l := len(nums)
	m := l / 2

	if l == 1 {
		return nums[0]
	}

	if nums[0] <= nums[m] {
		n1 := nums[0]
		n2 := findMin(nums[m:l])
		if n1 < n2 {
			return n1
		}
		return n2
	}

	n1 := nums[m]
	n2 := findMin(nums[0:m])

	if n1 < n2 {
		return n1
	}
	return n2
}

func Test153(t *testing.T) {
	Convey("test", t, func() {
		So(findMin([]int{3, 4, 5, 1, 2}), ShouldEqual, 1)
		So(findMin([]int{3, 4, 1, 2}), ShouldEqual, 1)
		So(findMin([]int{3, 4, 1, 2}), ShouldEqual, 1)
		So(findMin([]int{4, 5, 6, 7, 0, 1, 2}), ShouldEqual, 0)
	})
}
