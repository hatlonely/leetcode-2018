package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func minimumOperations(nums []int, start int, goal int) int {
	steps := [1001]int{}
	step := 1

	opNums := []int{start}
	for len(opNums) != 0 {
		var opNumsNew []int
		for _, op := range opNums {
			for _, num := range nums {
				s1 := op + num
				s2 := op - num
				s3 := op ^ num
				if s1 == goal || s2 == goal || s3 == goal {
					return step
				}
				if s1 >= 0 && s1 <= 1000 && steps[s1] == 0 {
					opNumsNew = append(opNumsNew, s1)
					steps[s1] = step
				}
				if s2 >= 0 && s2 <= 1000 && steps[s2] == 0 {
					opNumsNew = append(opNumsNew, s2)
					steps[s2] = step
				}
				if s3 >= 0 && s3 <= 1000 && steps[s3] == 0 {
					opNumsNew = append(opNumsNew, s3)
					steps[s3] = step
				}
			}
		}
		opNums = opNumsNew
		step++
	}

	return -1
}

func Test5916(t *testing.T) {
	Convey("Test5916", t, func() {
		So(minimumOperations([]int{1, 3}, 6, 4), ShouldEqual, 2)
		So(minimumOperations([]int{2, 4, 12}, 2, 12), ShouldEqual, 2)
		So(minimumOperations([]int{3, 5, 7}, 0, -4), ShouldEqual, 2)
		So(minimumOperations([]int{2, 8, 16}, 0, 1), ShouldEqual, -1)
		So(minimumOperations([]int{1}, 0, 3), ShouldEqual, 3)
	})
}
