#include <gtest/gtest.h>
#include <iostream>
#include <string>

class Solution {
   public:
    std::string encode(std::string longUrl) {
        return longUrl;
    }

    std::string decode(std::string shortUrl) {
        return shortUrl;
    }
};

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
