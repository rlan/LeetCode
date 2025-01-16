# Runtime 0 ms Beats 100.00%
class Solution:
    def isPalindrome(self, x: int) -> bool:
        digits = list(str(x))
        half = len(digits) // 2
        last = len(digits) - 1
        for ii in range(0, half+1):
            if not digits[ii] == digits[last - ii]:
                return False
            else:
                continue
        return True