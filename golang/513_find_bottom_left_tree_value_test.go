package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func findBottomLeftValue(root *TreeNode) int {
	st := []*TreeNode{}
	st = append(st, root)
	val := root.Val
	for len(st) != 0 {
		n := len(st)
		val = st[0].Val
		for i := 0; i < n; i++ {
			node := st[i]
			if node.Left != nil {
				st = append(st, node.Left)
			}
			if node.Right != nil {
				st = append(st, node.Right)
			}
		}
		st = st[n:]
	}
	return val
}

func Test(t *testing.T) {
	Convey("test", t, func() {

	})
}
