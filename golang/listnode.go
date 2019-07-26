package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewList(li []int) *ListNode {
	prev := &ListNode{}
	curr := prev
	for _, i := range li {
		curr.Next = &ListNode{Val: i}
		curr = curr.Next
	}

	return prev.Next
}

func ToList(li *ListNode) []int {
	var vs []int
	for li != nil {
		vs = append(vs, li.Val)
		li = li.Next
	}
	return vs
}
