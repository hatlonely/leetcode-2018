package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	pre := &ListNode{}
	node := pre
	c := 0
	for l1 != nil && l2 != nil {
		node.Next = &ListNode{}
		node = node.Next
		node.Val = (l1.Val + l2.Val + c) % 10
		c = (l1.Val + l2.Val + c) / 10
		l1 = l1.Next
		l2 = l2.Next
	}
	for l1 != nil {
		node.Next = &ListNode{}
		node = node.Next
		node.Val = (l1.Val + c) % 10
		c = (l1.Val + c) / 10
		l1 = l1.Next
	}
	for l2 != nil {
		node.Next = &ListNode{}
		node = node.Next
		node.Val = (l2.Val + c) % 10
		c = (l2.Val + c) / 10
		l2 = l2.Next
	}
	if c != 0 {
		node.Next = &ListNode{}
		node = node.Next
		node.Val = c
	}

	return pre.Next
}

func Test2(t *testing.T) {
	Convey("add two numbers", t, func() {
		So(ToList(addTwoNumbers(NewList([]int{2, 4, 3}), NewList([]int{5, 6, 4}))), ShouldResemble, []int{7, 0, 8})
		So(ToList(addTwoNumbers(NewList([]int{0}), NewList([]int{0}))), ShouldResemble, []int{0})
		So(ToList(addTwoNumbers(NewList([]int{9, 9, 9, 9, 9, 9, 9}), NewList([]int{9, 9, 9, 9}))), ShouldResemble, []int{8, 9, 9, 9, 0, 0, 0, 1})
	})
}
