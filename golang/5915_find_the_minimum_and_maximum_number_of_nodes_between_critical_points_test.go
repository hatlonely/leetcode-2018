package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func nodesBetweenCriticalPoints(head *ListNode) []int {
	if head == nil {
		return []int{-1, -1}
	}

	lastValue := head.Val
	node := head.Next
	idx := 1

	firstIdx := 0
	lastIdx := 0
	prevIdx := 0

	minDistance := -1

	for node.Next != nil {
		if node.Val > lastValue && node.Val > node.Next.Val {
			if prevIdx != 0 && (idx-prevIdx < minDistance || minDistance == -1) {
				minDistance = idx - prevIdx
			}

			prevIdx = idx
			if firstIdx == 0 {
				firstIdx = idx
			}
			lastIdx = idx
		}
		if node.Val < lastValue && node.Val < node.Next.Val {
			if prevIdx != 0 && (idx-prevIdx < minDistance || minDistance == -1) {
				minDistance = idx - prevIdx
			}

			prevIdx = idx
			if firstIdx == 0 {
				firstIdx = idx
			}
			lastIdx = idx
		}

		idx++
		lastValue = node.Val
		node = node.Next
	}

	if prevIdx == 0 || firstIdx == lastIdx {
		return []int{-1, -1}
	}

	return []int{minDistance, lastIdx - firstIdx}
}

func Test5915(t *testing.T) {
	Convey("Test5915", t, func() {
		So(nodesBetweenCriticalPoints(NewList([]int{3, 1})), ShouldResemble, []int{-1, -1})
		So(nodesBetweenCriticalPoints(NewList([]int{5, 3, 1, 2, 5, 1, 2})), ShouldResemble, []int{1, 3})
		So(nodesBetweenCriticalPoints(NewList([]int{1, 3, 2, 2, 3, 2, 2, 2, 7})), ShouldResemble, []int{3, 3})
		So(nodesBetweenCriticalPoints(NewList([]int{2, 3, 3, 2})), ShouldResemble, []int{-1, -1})
	})
}
