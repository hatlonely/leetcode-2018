package leetcode

import (
	"strconv"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func fizzBuzz(n int) []string {
	fbs := make([]string, 0, n)
	for i := 1; i <= n; i++ {
		if i%15 == 0 {
			fbs = append(fbs, "FizzBuzz")
		} else if i%3 == 0 {
			fbs = append(fbs, "Fizz")
		} else if i%5 == 0 {
			fbs = append(fbs, "Buzz")
		} else {
			fbs = append(fbs, strconv.Itoa(i))
		}
	}
	return fbs
}

func Test412(t *testing.T) {
	Convey("test", t, func() {

	})
}
