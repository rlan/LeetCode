# Runtime 0 ms Beats 100.00%
# Memory 17.97 MB Beats 15.47%
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common = 0
        num_str = len(strs)
        len_str = [len(x) for x in strs]
        min_len = min(len_str)
        for ii in range(min_len):
            all_same = True
            for jj in range(1, num_str):
                if not strs[0][ii] == strs[jj][ii]:
                    all_same = False
                    break
            if all_same:
                common = common + 1
            else:
                break

        return strs[0][0:common]