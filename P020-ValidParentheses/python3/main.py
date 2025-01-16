# Runtime 3 ms Beats 23.98%
# Memory 17.78 MB Beats 40.56%
class Solution:
    def isValid(self, s: str) -> bool:
        pair = {'(':')', '{':'}', '[':']'}
        open_paran = ['(', '{', '[']
        stack = []
        for x in s:
            if x in open_paran:
                stack.append(x)
            else:
                if len(stack):
                    if pair[stack[-1]] == x:
                        stack.pop()
                    else:
                        return False
                else:
                    return False

        return len(stack) == 0