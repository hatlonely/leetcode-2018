package leetcode

import "testing"
import . "github.com/smartystreets/goconvey/convey"

func transpose(matrix [][]int) [][]int {
	m := len(matrix)
	n := len(matrix[0])
	result := make([][]int, n)
	for i := range result {
		result[i] = make([]int, m)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			result[j][i] = matrix[i][j]
		}
	}

	return result
}

func TestTranspoe(t *testing.T) {
	Convey("test", t, func() {
		So(transpose([][]int{
			{1, 2, 3},
			{4, 5, 6},
		}), ShouldResemble, [][]int{
			{1, 4},
			{2, 5},
			{3, 6},
		})
	})
}
