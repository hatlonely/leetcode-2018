package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func kthSmallest(root *TreeNode, k int) int {
	st := []*TreeNode{}
	node := root
	for node != nil {
		st = append(st, node)
		node = node.Left
	}
	for len(st) > 0 {
		node := st[len(st)-1]
		st = st[:len(st)-1]
		k--
		if k == 0 {
			return node.Val
		}
		node = node.Right
		for node != nil {
			st = append(st, node)
			node = node.Left
		}
	}

	return -1
}

func Test230(t *testing.T) {
	Convey("test", t, func() {

	})
}
