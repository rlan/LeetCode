//
//  LeetCode
//  Algorithm 28 Implement strStr()
//
//  Created by Rick Lan on 4/10/17.
//  See LICENSE
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.size() > haystack.size())
            return -1;
        if (needle.size() == 0)
            return 0;
        
        int first = -1;
        for (unsigned long ii = 0; ii < haystack.size() - needle.size() + 1; ii++) {
            bool found = false;
            if (haystack[ii] == needle[0]) {
                unsigned long count = 1;
                for(unsigned long jj = 1; jj < needle.size(); jj++) {
                    if (haystack[ii+jj] == needle[jj])
                        count++;
                }
                if (count == needle.size()) {
                    found = true;
                    first = ii;
                }
            }
            if (found) break;
        }
        
        return first;
    }
};

int main(int argc, const char * argv[]) {

    string haystack;
    string needle;
    //haystack = ""; needle = ""; // 0
    //haystack = "a"; needle = ""; // 0
    //haystack = ""; needle = "a"; // -1
    //haystack = "a"; needle = "ab"; // -1
    //haystack = "abcdef"; needle = "abcdef"; // 0
    //haystack = "abcdef"; needle = "efg"; // -1
    haystack = "abcdef"; needle = "aefg"; // -1
    Solution solution;
    
    int sol = solution.strStr(haystack, needle);
    cout << "sol " << sol << endl;
    return 0;
}
