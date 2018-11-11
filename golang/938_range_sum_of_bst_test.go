package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func rangeSumBST(root *TreeNode, L int, R int) int {
	if root == nil {
		return 0
	}
	lv := rangeSumBST(root.Left, L, R)
	rv := rangeSumBST(root.Right, L, R)
	if root.Val >= L && root.Val <= R {
		return lv + rv + root.Val
	}
	return lv + rv
}

func Test938(t *testing.T) {
	Convey("test", t, func() {

	})
}
