#include <gtest/gtest.h>
#include <string>

class Solution {
   public:
    std::string simplifyPath(const std::string& path) {
        int         n = path.length();
        std::string simplePath(n, ' ');
        int         len = 0;
        for (int i = 0; i < n;) {
            int l = i + 1;
            int r = i + 1;
            if (l >= n) {
                break;
            }
            while (r < n && path[r] != '/') {
                r++;
            }
            if (r - l == 0) {
            } else if (r - l == 1 && path[l] == '.') {
            } else if (r - l == 2 && path[l] == '.' && path[l + 1] == '.') {
                while (len > 0 && simplePath[--len] != '/') {
                }
            } else {
                for (int j = i; j < r; j++) {
                    simplePath[len++] = path[j];
                }
            }
            i = r;
        }
        if (len == 0) {
            return "/";
        }
        simplePath.resize(len);
        return simplePath;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(test, case1) {
    Solution solution;
    EXPECT_EQ(solution.simplifyPath("/home/"), "/home");
    EXPECT_EQ(solution.simplifyPath("/a/./b/../../c/"), "/c");
    EXPECT_EQ(solution.simplifyPath("/"), "/");
    EXPECT_EQ(solution.simplifyPath("/home/foo/.ssh/../.ssh2/authorized_keys/"), "/home/foo/.ssh2/authorized_keys");
}