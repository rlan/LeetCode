# Runtime 3 ms Beats 80.87%
class Solution:
    def romanToInt(self, s: str) -> int:
        numerals = list(s)
        # convert numerals to decimal
        n2int = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        decimals = [n2int[x] for x in numerals]
        # summation
        value = decimals[-1]
        for ii in range(-2, -len(decimals)-1, -1):
            x = decimals[ii]
            if x < decimals[ii+1]:
                value = value - x
            else:
                value = value + x
        return value
