//
//  LeetCode
//  Algorithm 35 Search Insert Position
//
//  Created by Rick Lan on 4/11/17.
//  See LICENSE
//

#include <iostream>
#include <vector>
#include "vector_util.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        unsigned long ii = 0;
        
        for (ii = 0; ii < nums.size(); ii++) {
            if (target <= nums[ii]) {
                cout << "break " << ii << endl;
                break;
            }
        }
        return ii;
    }
};

int main(int argc, const char * argv[]) {
    
    int target;
    vector<int> vec;
    
    //target = 5; readVec(4, "1 3 5 6", vec); // 2
    //target = 2; readVec(4, "1 3 5 6", vec); // 1
    //target = 7; readVec(4, "1 3 5 6", vec); // 4
    target = 0; readVec(4, "1 3 5 6", vec); // 0
    
    cout << "target " << target << endl;
    displayVec(vec);
    Solution solution;
    int sol = solution.searchInsert(vec, target);
    cout << "sol " << sol << endl;

    return 0;
}
