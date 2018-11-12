package leetcode

import (
	"fmt"
	"strconv"
	"strings"
	"testing"

	. "github.com/smartystreets/goconvey/convey"
)

func subdomainVisits(cpdomains []string) []string {
	vt := map[string]int{}
	for _, cpdomain := range cpdomains {
		timesDomain := strings.Split(cpdomain, " ")
		times, _ := strconv.Atoi(timesDomain[0])
		domain := timesDomain[1]
		vt[domain] += times
		for i := range domain {
			if domain[i] != '.' {
				continue
			}
			vt[domain[i+1:]] += times
		}
	}
	vts := make([]string, 0, len(vt))
	for v, t := range vt {
		vts = append(vts, fmt.Sprintf("%d %s", t, v))
	}

	return vts
}

func Test811(t *testing.T) {
	Convey("test", t, func() {
		vts := subdomainVisits([]string{
			"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org",
		})
		for _, w := range []string{
			"901 mail.com", "50 yahoo.com", "900 google.mail.com", "5 wiki.org", "5 org", "1 intel.mail.com", "951 com",
		} {
			So(vts, ShouldContain, w)
		}
	})
}
