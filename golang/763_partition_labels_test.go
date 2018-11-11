package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func partitionLabels(str string) []int {
	subs := []int{}
	maxMap := map[byte]int{}

	for i := range str {
		c := str[i]
		maxMap[c] = i
	}

	l := 0
	for l != len(str) {
		r := l
		m := maxMap[str[l]]
		for r != m {
			r++
			n := maxMap[str[r]]
			if m < n {
				m = n
			}
		}
		subs = append(subs, r-l+1)
		l = r + 1
	}

	return subs
}

func Test763(t *testing.T) {
	Convey("test", t, func() {
		So(partitionLabels("ababcbacadefegdehijhklij"), ShouldResemble, []int{9, 7, 8})
	})
}
