package leetcode

import (
	"sort"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func isSubSequence(str1, str2 string) bool {
	if len(str1) > len(str2) {
		return false
	}
	i := 0
	j := 0
	for i < len(str1) && j < len(str2) {
		for j < len(str2) && str1[i] != str2[j] {
			j++
		}
		if j < len(str2) {
			i++
			j++
		}
	}
	return i == len(str1)
}

func findLUSlengthII(strs []string) int {
	m := map[string]int{}
	for _, str := range strs {
		m[str]++
	}

	strs1 := []string{}
	strs2 := []string{}
	for str, times := range m {
		if times == 1 {
			strs1 = append(strs1, str)
		} else {
			strs2 = append(strs2, str)
		}
	}

	sort.Slice(strs1, func(i, j int) bool {
		return len(strs1[i]) > len(strs1[j])
	})

	for _, str1 := range strs1 {
		isSub := false
		for _, str2 := range strs2 {
			if isSubSequence(str1, str2) {
				isSub = true
				break
			}
		}
		if !isSub {
			return len(str1)
		}
	}

	return -1
}

func Test522(t *testing.T) {
	Convey("test", t, func() {
		So(findLUSlengthII([]string{
			"aba", "cdc", "eae",
		}), ShouldEqual, 3)

		So(findLUSlengthII([]string{
			"aabbcc", "aabbcc", "cb",
		}), ShouldEqual, 2)

		So(isSubSequence("bc", "aabbcc"), ShouldBeTrue)
		So(isSubSequence("cb", "aabbcc"), ShouldBeFalse)
	})
}
