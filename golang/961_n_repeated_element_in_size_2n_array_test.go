package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func repeatedNTimes(nums []int) int {
	nset := map[int]struct{}{}
	for _, num := range nums {
		if _, ok := nset[num]; ok {
			return num
		}
		nset[num] = struct{}{}
	}

	return 0
}

func Test961(t *testing.T) {
	Convey("test", t, func() {
		So(repeatedNTimes([]int{2, 1, 2, 5, 3, 2}), ShouldEqual, 2)
	})
}
