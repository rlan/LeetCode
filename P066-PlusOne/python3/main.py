# Runtime 0 ms Beats 100.00%
# Memory 17.60 MB Beats 39.25%
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = len(digits)-1
        for ii in range(len(digits)-1, -1, -1):
            if not digits[ii] == 9:
                digits[ii] = digits[ii] + 1
                break
            else:
                carry = ii-1
                digits[ii] = 0

        if carry == -1:
            digits.insert(0, 1)
        return digits
