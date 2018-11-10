package leetcode

import (
	"math"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func smallestRangeI(nums []int, k int) int {
	max := math.MinInt32
	min := math.MaxInt32
	for _, num := range nums {
		if max < num {
			max = num
		}
		if min > num {
			min = num
		}
	}
	d := max - min
	d -= k * 2
	if d < 0 {
		return 0
	}
	return d
}

func Test908(t *testing.T) {
	Convey("test", t, func() {
		So(smallestRangeI([]int{0, 10}, 2), ShouldEqual, 6)
	})
}
