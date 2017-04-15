//
//  LeetCode
//  Algorithm 58 Length Of Last Word
//
//  Created by Rick Lan on 4/15/17.
//  See LICENSE
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        if (s.size() == 0)
            return 0;
        
        int i = s.size()-1;
        // skip trailing spaces
        while ((s[i]==' ') && (i >= 0)) {
            i--;
        }
        
        if (i < 0)
            return 0;
        
        // find a space
        int count = 0;
        while ((s[i]!=' ') && (i>=0)) {
            i--;
            count++;
        }
        
        return count;
    }
};

int main(int argc, const char * argv[]) {

    string s;
    s = "";
    s = " ";
    s = "Hello World";
    s = "Hello World ";
    s = " Hello World ";
    s = " Hello World";
    s = "World";
    s = "World ";
    s = " World ";
    s = " World";
    
    Solution solution;
    int sol = solution.lengthOfLastWord(s);
    cout << "Sol " << sol << endl;
    return 0;
}
