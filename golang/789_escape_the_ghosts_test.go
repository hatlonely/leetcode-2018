package leetcode

import (
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}

	return a
}

func escapeGhosts(ghosts [][]int, target []int) bool {
	d0 := abs(target[0]) + abs(target[1])
	for _, ghost := range ghosts {
		di := abs(ghost[0]-target[0]) + abs(ghost[1]-target[1])
		if d0 >= di {
			return false
		}
	}

	return true
}

func Test789(t *testing.T) {
	Convey("test", t, func() {

	})
}
