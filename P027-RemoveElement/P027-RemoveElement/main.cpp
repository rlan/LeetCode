//
//  LeetCode
//  Algorithm 27 Remove Element
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
    int removeElement(vector<int>& nums, int val) {
        long N = nums.size();
        long start = 0;
        long end = N-1;
        
        while (start <= end) {
            if (nums[start] != val) {
                start++;
            } else {
                while (nums[end] == val) {
                    end--;
                }
                if (start < end) {
                    cout << "X [" << start << "] " << nums[start] << " [" << end << "] " << nums[end] << endl;
                    nums[start++] = nums[end--];
                }
            }
            cout << "Y start " << start << " end " << end << endl;
            displayVec(nums);
        }
        
        return start;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> vec;
    //readVec(4, "3 2 2 3", vec);
    //readVec(4, "3 2 2 1", vec);
    //readVec(1, "1", vec);
    //readVec(3, "1 1 1", vec);
    //readVec(1, "3", vec);
    readVec(3, "3 3 3", vec);
    //readVec(7, "3 1 3 2 3 5 3", vec);
    //readVec(7, "3 1 3 3 3 5 3", vec);
    //readVec(3, "3 3 2", vec);
    displayVec(vec);
    
    Solution solution;
    int N = solution.removeElement(vec, 3);
    cout << "N " << N << endl;
    displayVec(vec);

    return 0;
}
