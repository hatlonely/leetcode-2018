package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func findDuplicates(nums []int) []int {
	dns := []int{}
	numset := map[int]struct{}{}
	for _, num := range nums {
		if _, ok := numset[num]; ok {
			dns = append(dns, num)
		}
		numset[num] = struct{}{}
	}

	return dns
}

func Test442(t *testing.T) {
	Convey("test", t, func() {
		So(findDuplicates([]int{4, 3, 2, 7, 8, 2, 3, 1}), ShouldResemble, []int{2, 3})
	})
}
