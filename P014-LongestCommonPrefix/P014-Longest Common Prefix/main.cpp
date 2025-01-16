//
//  LeetCode
//  Algorithm 14 Longest Common Prefix
//
//  Created by Rick Lan on 3/31/17.
//  See LICENSE
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.size() == 0)
            return "";
        for (unsigned long ii = 0; ii < strs.size(); ii++) {
            if (strs[ii].size() == 0)
                return "";
        }
        
        string sol = "";
        for (unsigned long ii = 0; ii < strs[0].size(); ii++) {
            bool same = true;
            for (unsigned long jj = 1; jj < strs.size(); jj++) {
                if (strs[0][ii] != strs[jj][ii]) {
                    same = false;
                    break;
                }
            }
            
            if (same) {
                sol.push_back(strs[0][ii]);
            } else {
                break;
            }
        }
        return sol;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<string> data;
    
    data.resize(3);
    data[0] = "aaa";
    data[1] = "aad";
    data[2] = "aab";
    
    string sol = solution.longestCommonPrefix(data);
    
    cout << "size " << sol.size() << " [" << sol << "]" << endl;
    
    return 0;
}
