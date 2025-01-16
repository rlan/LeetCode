# Runtime 7 ms Beats 43.14%
class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = list(s)
        # convert numerals to decimal
        n2int = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        decimals = [n2int[x] for x in numerals]
        # summation
        value = decimals[-1]
        for ii in range(1, len(decimals)):
            reverse = -ii - 1
            x = decimals[reverse]
            if x < decimals[reverse+1]:
                value = value - x
            else:
                value = value + x
        return value
