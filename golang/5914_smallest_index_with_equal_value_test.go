package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func smallestEqual(nums []int) int {
	for i := 0; i < len(nums); i++ {
		if nums[i] == i%10 {
			return i
		}
	}

	return -1
}

func Test5914(t *testing.T) {
	Convey("Test5914", t, func() {
		So(smallestEqual([]int{0, 1, 2}), ShouldEqual, 0)
		So(smallestEqual([]int{4, 3, 2, 1}), ShouldEqual, 2)
		So(smallestEqual([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}), ShouldEqual, -1)
		So(smallestEqual([]int{2, 1, 3, 5, 2}), ShouldEqual, 1)
	})
}
