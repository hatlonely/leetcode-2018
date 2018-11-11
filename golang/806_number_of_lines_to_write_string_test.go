package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func numberOfLines(widths []int, str string) []int {
	l := 0
	n := 1
	for i := range str {
		l += widths[int(str[i])-int('a')]
		if l > 100 {
			n++
			l = widths[int(str[i])-int('a')]
		}
	}
	return []int{n, l}
}

func Test806(t *testing.T) {
	Convey("test", t, func() {
		So(numberOfLines([]int{
			10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		}, "abcdefghijklmnopqrstuvwxyz",
		), ShouldResemble, []int{3, 60})

		So(numberOfLines([]int{
			4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
		}, "bbbcccdddaaa",
		), ShouldResemble, []int{2, 4})
	})
}
