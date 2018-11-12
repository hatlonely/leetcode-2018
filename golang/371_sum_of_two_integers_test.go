package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func getSum(a int, b int) int {
	for b != 0 {
		sum := a ^ b
		b = (a & b) << 1
		a = sum
	}

	return a
}

func Test371(t *testing.T) {
	Convey("test", t, func() {
		So(getSum(1, 2), ShouldEqual, 3)
		So(getSum(123, 5), ShouldEqual, 128)
	})
}
