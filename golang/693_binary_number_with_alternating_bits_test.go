package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func hasAlternatingBits(n int) bool {
	b0 := ^n & 1
	for n != 0 {
		b1 := n & 1
		if b0^b1 == 0 {
			return false
		}
		n >>= 1
		b0 = b1
	}
	return true
}

func Test693(t *testing.T) {
	Convey("test", t, func() {
		So(hasAlternatingBits(5), ShouldBeTrue)
	})
}
