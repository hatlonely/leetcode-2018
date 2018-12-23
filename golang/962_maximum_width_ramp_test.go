package leetcode

import (
	"math"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func maxWidthRamp(nums []int) int {
	i := 0
	j := 0
	k := math.MaxInt64
	for l := range nums {
		r := len(nums) - 1
		if nums[l] >= k {
			continue
		}
		for l < r {
			if nums[l] <= nums[r] {
				break
			}
			r--
		}
		if k > nums[l] {
			k = nums[l]
		}
		if r-l > j-i {
			i = l
			j = r
		}
	}

	return j - i
}

func Test962(t *testing.T) {
	Convey("test", t, func() {
		So(maxWidthRamp([]int{9, 8, 1, 0, 1, 9, 4, 0, 4, 1}), ShouldEqual, 7)
		So(maxWidthRamp([]int{6, 0, 8, 2, 1, 5}), ShouldEqual, 4)
		So(maxWidthRamp([]int{0, 1}), ShouldEqual, 1)
	})
}
