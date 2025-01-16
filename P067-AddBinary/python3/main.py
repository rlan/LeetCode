# Runtime 0 ms Beats 100.00%
# Memory 17.88 MB Beats 26.74%
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        int_a = int(a, base=2)
        int_b = int(b, base=2)
        out = int_a + int_b
        return format(out, 'b')
