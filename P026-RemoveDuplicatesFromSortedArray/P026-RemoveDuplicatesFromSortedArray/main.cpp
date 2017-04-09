//
//  main.cpp
//  Algorithm 26 Remove Duplicates From Sorted Array
//
//  Created by Rick Lan on 4/9/17.
//  See LICENSE
//

#include <iostream>
#include <vector>
#include "vector_util.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        unsigned long N = nums.size();
        if (N <= 1) {
            return N;
        }
        unsigned long ii = 0;
        unsigned long jj = 1;
        while (jj < N) {
            while ((nums[ii] == nums[jj]) && (jj<N)) {
                jj++;
            }
            //cout << "A " << ii << " " << jj << endl;
            if (jj < N) {
                nums[++ii] = nums[jj++];
            } else {
                break;
            }
        }
        
        return ii+1;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> vec;
    //readVec(3, "1 2 3", vec);
    //readVec(3, "1 1 2", vec);
    //readVec(6, "1 1 1 2 2 2", vec);
    //readVec(5, "1 1 2 3 4", vec);
    readVec(5, "1 2 3 3 3", vec);
    displayVec(vec);
    
    Solution solution;
    int len = solution.removeDuplicates(vec);
    cout << "len " << len << endl;
    displayVec(vec);
    return 0;
}
