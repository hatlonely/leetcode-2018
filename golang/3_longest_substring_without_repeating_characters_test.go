package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func lengthOfLongestSubstring(str string) int {
	m := [128]bool{}
	length := 0
	idx := 0
	for i := 0; i < len(str); i++ {
		if m[str[i]] {
			if i-idx > length {
				length = i - idx
			}
			for str[idx] != str[i] {
				m[str[idx]] = false
				idx++
			}
			idx++
		} else {
			m[str[i]] = true
		}
	}
	if len(str)-idx > length {
		length = len(str) - idx
	}

	return length
}

func Test3(t *testing.T) {
	Convey("test lengthOfLongestSubstring", t, func() {
		So(lengthOfLongestSubstring("abcabcbb"), ShouldEqual, 3)
		So(lengthOfLongestSubstring("bbbbb"), ShouldEqual, 1)
		So(lengthOfLongestSubstring("pwwkew"), ShouldEqual, 3)
		So(lengthOfLongestSubstring(""), ShouldEqual, 0)
		So(lengthOfLongestSubstring(" "), ShouldEqual, 1)
		So(lengthOfLongestSubstring("tmmzuxt"), ShouldEqual, 5)
	})
}
