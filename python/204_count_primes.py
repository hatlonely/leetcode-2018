#!/usr/bin/env python3

import math


class Solution1:
    def countPrimes(self, n):
        primes = [2, 3, 5, 7]
        for i in range(0, len(primes)):
            if n <= primes[i]:
                return i
        for i in range(11, n, 2):
            isPrime = True
            m = math.sqrt(i)
            for j in range(1, len(primes)):
                if primes[j] > m:
                    break
                if i % primes[j] == 0:
                    isPrime = False
                    break
            if isPrime:
                primes.append(i)
        return len(primes)


class Solution:
    def countPrimes(self, n):
        if n <= 2:
            return 0
        bs = [True] * n
        m = int(math.sqrt(n)) + 1
        count = n - 2
        for i in range(2, m):
            if not bs[i]:
                continue
            for j in range(i * i, n, i):
                if bs[j]:
                    bs[j] = False
                    count -= 1
        return count


if __name__ == '__main__':
    solution = Solution()
    print(solution.countPrimes(20), 8)
    print(solution.countPrimes(2), 0)
    print(solution.countPrimes(11), 4)
    print(solution.countPrimes(12), 5)
    print(solution.countPrimes(499979), 41537)
