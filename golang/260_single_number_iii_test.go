package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func singleNumber(nums []int) []int {
	numTimesMap := map[int]int{}
	for _, num := range nums {
		numTimesMap[num]++
	}
	result := []int{}
	for num, times := range numTimesMap {
		if times == 1 {
			result = append(result, num)
		}
	}
	return result
}

func TestSingNumberIII(t *testing.T) {
	Convey("test", t, func() {
		So(singleNumber([]int{1, 2, 1, 3, 2, 5}), ShouldResemble, []int{3, 5})
	})
}
