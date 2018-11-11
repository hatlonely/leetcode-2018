package leetcode

import (
	"fmt"
	"strconv"
	"strings"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func complexNumberMultiply(a string, b string) string {
	xya := strings.Split(a, "+")
	xa, _ := strconv.Atoi(xya[0])
	ya, _ := strconv.Atoi(xya[1][:len(xya[1])-1])

	xyb := strings.Split(b, "+")
	xb, _ := strconv.Atoi(xyb[0])
	yb, _ := strconv.Atoi(xyb[1][:len(xyb[1])-1])

	return fmt.Sprintf("%d+%di", xa*xb-ya*yb, xa*yb+xb*ya)
}

func Test537(t *testing.T) {
	Convey("test", t, func() {
		So(complexNumberMultiply("1+-1i", "1+-1i"), ShouldEqual, "0+-2i")
	})
}
