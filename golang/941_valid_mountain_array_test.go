package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func validMountainArray(nums []int) bool {
	if len(nums) < 3 {
		return false
	}

	i := 1
	for ; i < len(nums); i++ {
		if nums[i] <= nums[i-1] {
			break
		}
	}

	if i == len(nums) || i == 1 {
		return false
	}

	for ; i < len(nums); i++ {
		if nums[i] >= nums[i-1] {
			break
		}
	}

	return i == len(nums)
}

func Test941(t *testing.T) {
	Convey("test", t, func() {
		So(validMountainArray([]int{
			2, 1,
		}), ShouldBeFalse)
		So(validMountainArray([]int{
			2, 5, 5,
		}), ShouldBeFalse)
		So(validMountainArray([]int{
			0, 2, 1, 0,
		}), ShouldBeTrue)
		So(validMountainArray([]int{
			3, 2, 1,
		}), ShouldBeFalse)
	})
}
