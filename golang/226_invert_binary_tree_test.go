package leetcode

import "testing"
import . "github.com/smartystreets/goconvey/convey"

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
