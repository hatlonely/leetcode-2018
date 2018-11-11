package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func shortestToChar(str string, ch byte) []int {
	ds := make([]int, len(str))
	i := 0
	for i < len(str) {
		if str[i] == ch {
			break
		}
		i++
	}
	for j := 0; j < i; j++ {
		ds[j] = i - j
	}
	i++
	for i < len(str) {
		if str[i] == ch {
			ds[i] = 0
			for ds[i-1] > ds[i]+1 {
				ds[i-1] = ds[i] + 1
				i--
			}
		} else {
			ds[i] = ds[i-1] + 1
		}
		i++
	}

	return ds
}

func Test821(t *testing.T) {
	Convey("test", t, func() {
		So(shortestToChar("loveleetcode", 'e'), ShouldResemble, []int{
			3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0,
		})
	})
}
