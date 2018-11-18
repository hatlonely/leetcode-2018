package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func minDeletionSize(strs []string) int {
	n := len(strs[0])
	c := 0
	for i := 0; i < n; i++ {
		isOrder := true
		lastc := int('a') - 1
		for _, str := range strs {
			if int(str[i]) < lastc {
				isOrder = false
				break
			}
			lastc = int(str[i])
		}
		if !isOrder {
			c++
		}
	}

	return c
}

func Test944(t *testing.T) {
	Convey("test", t, func() {
		So(minDeletionSize([]string{
			"a", "b",
		}), ShouldEqual, 0)
	})
	Convey("test", t, func() {
		So(minDeletionSize([]string{
			"cba", "daf", "ghi",
		}), ShouldEqual, 1)
	})
}
