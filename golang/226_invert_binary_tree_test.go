package leetcode

import "testing"
import . "github.com/smartystreets/goconvey/convey"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left, root.Right = root.Right, root.Left
	invertTree(root.Right)
	invertTree(root.Left)
	return root
}

func TestInvertTree(t *testing.T) {
	Convey("test", t, func() {

	})
}
