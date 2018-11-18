package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func diStringMatch(str string) []int {
	l := 0
	r := len(str)
	nums := make([]int, r+1)
	for i, c := range str {
		if c == 'I' {
			nums[i] = l
			l++
		} else {
			nums[i] = r
			r--
		}
	}
	nums[len(str)] = l
	return nums
}

func Test942(t *testing.T) {
	Convey("test", t, func() {
		So(diStringMatch("IDID"), ShouldResemble, []int{
			0, 4, 1, 3, 2,
		})

		So(diStringMatch("DDI"), ShouldResemble, []int{
			3, 2, 0, 1,
		})
	})
}
