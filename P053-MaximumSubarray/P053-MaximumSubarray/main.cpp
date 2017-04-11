//
//  LeetCode
//  Algorithm 53 Maximum Subarray
//
//  Created by Rick Lan on 4/11/17.
//  See LICENSE
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "vector_util.h"

using namespace std;

/*
 O(n) = n^2
 Must search over
 
 x0
 x0+x1        x1
 x0+x1+x2     x1+x2     x2
 x0+x1+x2+x3  x1+x2+x3  x2+x3  x3
 */
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sol = nums[0];
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for (unsigned long ii = 1; ii < sums.size(); ii++) {
            sums[ii] = sums[ii-1] + nums[ii];
            sol = max(sol, sums[ii]);
        }
        for (unsigned long ii = 0; ii < sums.size(); ii++) {
            //cout << ii << ": ";
            for (unsigned long jj = ii+1; jj < sums.size(); jj++) {
                //cout << jj << " ";
                sums[jj] = sums[jj] - nums[ii];
                sol = max(sol, sums[jj]);
            }
            //cout << endl;
        }
        return sol;
    }
};
 */

/*
 Here is the sub-problem we state: denote local_max[i] as the max-sub-array-sum that ends with nums[i]. The relationship between the two steps is simple: local_max[i + 1] = max (local_max[i] + nums[i + 1], nums[i + 1]).
 
 Now, all we have to do is to scan through the array, and find which local_max[i] is the maximum of all the local_maxs. */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        
        int local_max = nums[0];
        int global_max = nums[0];
        size_t N  = nums.size();
        for (size_t i = 1; i != N; ++i) {
            local_max  = max(local_max + nums[i], nums[i]);
            global_max = max(local_max, global_max);
        }
        
        return global_max;
    }
};



int main(int argc, const char * argv[]) {

    vector<int> vec;
    
    //readVec(9, "-2 1 -3 4 -1 2 1 -5 4", vec); // 6
    readVec(3, "-2 -1 -2", vec); // -1
    
    displayVec(vec);
    Solution solution;
    int sol = solution.maxSubArray(vec);
    cout << "sol " << sol << endl;
    
    return 0;
}
