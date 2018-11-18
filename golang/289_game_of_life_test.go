package leetcode

import (
	"fmt"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func gameOfLife(board [][]int) {
	m := len(board)
	n := len(board[0])
	bd := make([][]int, m)
	for i := 0; i < m; i++ {
		bd[i] = make([]int, n)
		for j := 0; j < n; j++ {
			bd[i][j] = board[i][j]
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			life := 0
			dead := 0
			if i-1 >= 0 {
				if j-1 >= 0 {
					if bd[i-1][j-1] == 1 {
						life++
					} else {
						dead++
					}
				}
				if bd[i-1][j] == 1 {
					life++
				} else {
					dead++
				}
				if j+1 < n {
					if bd[i-1][j+1] == 1 {
						life++
					} else {
						dead++
					}
				}
			}

			if j-1 >= 0 {
				if bd[i][j-1] == 1 {
					life++
				} else {
					dead++
				}
			}
			if j+1 < n {
				if bd[i][j+1] == 1 {
					life++
				} else {
					dead++
				}
			}

			if i+1 < m {
				if j-1 >= 0 {
					if bd[i+1][j-1] == 1 {
						life++
					} else {
						dead++
					}
				}
				if bd[i+1][j] == 1 {
					life++
				} else {
					dead++
				}
				if j+1 < n {
					if bd[i+1][j+1] == 1 {
						life++
					} else {
						dead++
					}
				}
			}
			fmt.Println(i, j, dead, life)
			if board[i][j] == 1 {
				if life < 2 || life > 3 {
					board[i][j] = 0
				}
			} else {
				if life == 3 {
					board[i][j] = 1
				}
			}
		}
	}
}

func Test289(t *testing.T) {
	Convey("test", t, func() {
		board := [][]int{
			{0, 1, 0},
			{0, 0, 1},
			{1, 1, 1},
			{0, 0, 0},
		}
		gameOfLife(board)
		So(board, ShouldResemble, [][]int{
			{0, 0, 0},
			{1, 0, 1},
			{0, 1, 1},
			{0, 1, 0},
		})
	})
}
