#!/usr/bin/env python3


class Solution:
    def evalRPN(self, tokens):
        stack = []
        for token in tokens:
            if token in {'+', '-', '*', '/'}:
                num2 = stack.pop()
                num1 = stack.pop()
                if token == '+':
                    stack.append(num1 + num2)
                if token == '-':
                    stack.append(num1 - num2)
                if token == '*':
                    stack.append(num1 * num2)
                if token == '/':
                    stack.append(int(num1 / num2))
            else:
                stack.append(int(token))
        return stack.pop()


if __name__ == '__main__':
    solution = Solution()
    print(solution.evalRPN(["10", "6", "9", "3", "+",
                            "-11", "*", "/", "*", "17", "+", "5", "+"]), 22)
