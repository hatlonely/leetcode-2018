package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func longestPalindrome(str string) string {
	var palindrome string

	for i := 0; i < len(str); i++ {
		m := i
		n := i
		for j := 0; m-1 >= 0 && n+1 < len(str) && str[m-1] == str[n+1]; j++ {
			m--
			n++
		}
		if len(palindrome) < n+1-m {
			palindrome = str[m : n+1]
		}
	}
	for i := 0; i < len(str)-1; i++ {
		m := i
		n := i + 1
		if str[m] != str[n] {
			continue
		}
		for j := 0; m-1 >= 0 && n+1 < len(str) && str[m-1] == str[n+1]; j++ {
			m--
			n++
		}
		if len(palindrome) < n+1-m {
			palindrome = str[m : n+1]
		}
	}

	return palindrome
}

func Test5(t *testing.T) {
	Convey("test longestPalindrome", t, func() {
		So(longestPalindrome("babad"), ShouldBeIn, []string{"bab", "aba"})
		So(longestPalindrome("cbbd"), ShouldEqual, "bb")
		So(longestPalindrome("a"), ShouldEqual, "a")
		So(longestPalindrome("ac"), ShouldBeIn, []string{"a", "c"})
	})
}
