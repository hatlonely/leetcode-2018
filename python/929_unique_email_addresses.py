#!/usr/bin/env python3


class Solution:
    def numUniqueEmails(self, emails):
        emailset = set()
        for email in emails:
            vals = email.split('@')
            emailset.add(
                vals[0].split('+')[0].replace('.', '') + '@' + vals[1]
            )
        return len(emailset)


if __name__ == '__main__':
    solution = Solution()
    print(solution.numUniqueEmails([
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com",
    ]), 2)
