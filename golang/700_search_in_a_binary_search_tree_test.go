package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func searchBST(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val < val {
		return searchBST(root.Right, val)
	}
	if root.Val > val {
		return searchBST(root.Left, val)
	}
	return root
}

func Test700(t *testing.T) {
	Convey("test", t, func() {

	})
}
