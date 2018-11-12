package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func findLUSlength(a string, b string) int {
	if len(a) < len(b) {
		return len(b)
	}

	if len(b) < len(a) {
		return len(a)
	}

	if a == b {
		return -1
	}

	return len(a)
}

func Test(t *testing.T) {
	Convey("test", t, func() {
		So(findLUSlength("aba", "cdc"), ShouldEqual, 3)
	})
}
