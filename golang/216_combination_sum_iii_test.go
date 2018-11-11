package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func combinationSum3Helper(k int, n int, idx int) [][]int {
	if k == 1 {
		if n > idx && n <= 9 {
			return [][]int{{n}}
		}
		return [][]int{}
	}
	combinations := [][]int{}
	for i := idx + 1; i <= 9; i++ {
		for _, combination := range combinationSum3Helper(k-1, n-i, i) {
			combination = append(combination, i)
			combinations = append(combinations, combination)
		}
	}
	return combinations
}

func combinationSum3(k int, n int) [][]int {
	return combinationSum3Helper(k, n, 0)
}

func Test216(t *testing.T) {
	Convey("test", t, func() {
		So(combinationSum3(3, 7), ShouldResemble, [][]int{
			{1, 2, 4},
		})
	})
}
