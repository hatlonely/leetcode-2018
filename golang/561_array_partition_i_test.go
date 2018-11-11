package leetcode

import (
	"sort"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func arrayPairSum(nums []int) int {
	sort.Ints(nums)
	sum := 0
	for i := 0; i < len(nums); i += 2 {
		sum += nums[i]
	}
	return sum
}

func Test561(t *testing.T) {
	Convey("test", t, func() {
		So(arrayPairSum([]int{1, 4, 2, 3}), ShouldEqual, 4)
	})
}
