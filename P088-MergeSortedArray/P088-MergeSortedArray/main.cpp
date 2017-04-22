//
//  LeetCode
//  Algorithm 88 Merge Sorted Array
//
//  Created by Rick Lan on 4/22/17.
//  See LICENSE
//

#include <iostream>
#include "vector_util.h"

using namespace std;
/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 (ascending)
 
 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold 
 additional elements from nums2. The number of elements initialized in nums1 and nums2 are m 
 and n respectively.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     
        int end = m+n-1;
        int i = m-1;
        int j = n-1;
        cout << "end " << end << " i " << i << " j " << j << endl;
        while (end >= 0) {
            cout << "while1 end " << end << " i " << i << " j " << j << endl;
            if (i < 0) {
                nums1[end--] = nums2[j--];
            } else if (j < 0) {
                break;
            } else if (nums1[i] >= nums2[j]) {
                nums1[end--] = nums1[i--];
            } else {
                nums1[end--] = nums2[j--];
            }
            cout << "while2 end " << end << " i " << i << " j " << j << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums1;
    vector<int> nums2;
    
    //read(6, "1 3 5 0 0 0", nums1);
    //read(3, "2 4 6", nums2);
    //read(6, "3 0 0 0 0 0", nums1);
    //read(3, "2 4 6", nums2);
    read(6, "1 3 5 0 0 0", nums1);
    read(3, "2 4 6", nums2);

    cout << "nums1 ";
    display(nums1);
    cout << "nums2 ";
    display(nums2);
    
    Solution solution;
    solution.merge(nums1, 3, nums2, 1);
    cout << "sol ";
    display(nums1);
    

    return 0;
}
