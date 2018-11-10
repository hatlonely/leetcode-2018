package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func titleToNumber(s string) int {
	n := 0
	for _, c := range s {
		n *= 26
		n += int(c) - int('A') + 1
	}
	return n
}

func Test171(t *testing.T) {
	Convey("test", t, func() {
		So(titleToNumber("AA"), ShouldEqual, 27)
	})
}
