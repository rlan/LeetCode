//
//  LeetCode
//  Algorithm 66 Plus One
//
//  Created by Rick Lan on 4/15/17.
//  See LICENSE
//

#include <iostream>
#include <vector>
#include "vector_util.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // digits non-empty
        
        int d = digits.size()-1;
        
        while (digits[d] == 9) {
            digits[d] = 0;
            d--;
        }
        
        if (d < 0) {
            digits.insert(digits.begin(), 1);
        } else {
            digits[d]++;
        }
        
        return digits;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> v;
    //readVec(3, "1 2 3", v);
    //readVec(1, "9", v);
    readVec(2, "9 9", v);
    displayVec(v);
    Solution solution;
    v = solution.plusOne(v);
    displayVec(v);
    return 0;
}
