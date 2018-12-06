package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func allPossibleFBT(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{nil}
	}
	if n == 1 {
		return []*TreeNode{&TreeNode{0, nil, nil}}
	}

	nodes := []*TreeNode{}
	for i := 1; i < n-1; i++ {
		j := n - 1 - i
		lnodes := allPossibleFBT(i)
		rnodes := allPossibleFBT(j)
		for _, ln := range lnodes {
			for _, rn := range rnodes {
				node := &TreeNode{0, ln, rn}
				nodes = append(nodes, node)
			}
		}
	}

	return nodes
}

func Test(t *testing.T) {
	Convey("test", t, func() {
		allPossibleFBT(7)
	})
}
