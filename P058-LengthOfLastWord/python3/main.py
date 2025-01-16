# Runtime 0 ms Beats 100.00%
# Memory 17.86 MB Beats 18.64%
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split()
        return len(words[-1])
