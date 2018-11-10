package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func addDigits(n int) int {
	return 1 + (n-1)%9
}

func Test258(t *testing.T) {
	Convey("test", t, func() {
		So(addDigits(38), ShouldEqual, 2)
	})
}
