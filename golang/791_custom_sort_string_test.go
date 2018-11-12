package leetcode

import (
	"sort"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func customSortString(s string, t string) string {
	cv := map[rune]int{}
	for i, c := range s {
		cv[c] = i
	}
	r := []rune(t)
	sort.Slice(r, func(i, j int) bool {
		return cv[r[i]] < cv[r[j]]
	})
	return string(r)
}

func Test791(t *testing.T) {
	Convey("test", t, func() {
		So(customSortString("cba", "abcd"), ShouldEqual, "cdba")
	})
}
