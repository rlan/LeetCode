# Runtime 1010 ms Beats 14.37%
# Memory 17.64 MB Beats 39.84%
# Bruteforce
class Solution:
    def mySqrt(self, x: int) -> int:
        count = 1
        while count*count < x:
            count = count + 1

        if count*count == x:
            return count
        else:
            return count - 1
