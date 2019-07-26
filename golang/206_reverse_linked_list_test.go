package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func reverseList(head *ListNode) *ListNode {
	prev := &ListNode{}
	curr := head

	for curr != nil {
		temp := curr.Next
		curr.Next = prev.Next
		prev.Next = curr
		curr = temp
	}

	return prev.Next
}

func Test206(t *testing.T) {
	Convey("test", t, func() {
		So(ToList(reverseList(NewList([]int{1, 2, 3, 4, 5, 6}))), ShouldResemble, []int{6, 5, 4, 3, 2, 1})
	})
}
