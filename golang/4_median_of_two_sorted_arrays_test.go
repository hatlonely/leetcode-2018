package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func findKSortedArrays(nums1 []int, nums2 []int, k int) float64 {
	if len(nums1) == 0 {
		return float64(nums2[k])
	}
	if len(nums2) == 0 {
		return float64(nums1[k])
	}
	if k == 0 {
		if nums1[0] < nums2[0] {
			return float64(nums1[0])
		} else {
			return float64(nums2[0])
		}
	}

	m := (k+1)/2 - 1
	idx1 := m
	idx2 := m
	if idx1 >= len(nums1) {
		idx1 = len(nums1) - 1
	}
	if idx2 >= len(nums2) {
		idx2 = len(nums2) - 1
	}
	if nums1[idx1] <= nums2[idx2] {
		return findKSortedArrays(nums1[idx1+1:], nums2[:], k-idx1-1)
	}
	return findKSortedArrays(nums1[:], nums2[idx2+1:], k-idx2-1)
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n := len(nums1) + len(nums2)
	if n%2 == 0 {
		return (findKSortedArrays(nums1, nums2, n/2) + findKSortedArrays(nums1, nums2, n/2-1)) / 2.0
	}
	return findKSortedArrays(nums1, nums2, n/2)
}

func Test4(t *testing.T) {
	Convey("test lengthOfLongestSubstring", t, func() {
		So(findMedianSortedArrays([]int{1, 3}, []int{2}), ShouldEqual, 2.0)
		So(findMedianSortedArrays([]int{1, 2}, []int{3, 4}), ShouldEqual, 2.5)
		So(findMedianSortedArrays([]int{0, 0}, []int{0, 0}), ShouldEqual, 0.0)
		So(findMedianSortedArrays([]int{}, []int{1}), ShouldEqual, 1.0)
		So(findMedianSortedArrays([]int{2}, []int{}), ShouldEqual, 2.0)
		So(findMedianSortedArrays([]int{0, 0, 0, 0, 0}, []int{-1, 0, 0, 0, 0, 0, 1}), ShouldEqual, 0.0)
	})
}
