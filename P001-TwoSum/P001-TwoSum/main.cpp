//
//  LeetCode
//  Algorithm 1 Two Sum
//
//  Created by Rick Lan on 3/30/17.
//  See LICENSE
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> sol(2, -1);
        for (unsigned long ii = 0; ii < nums.size(); ii++) {
            for (unsigned long jj = ii+1; jj < nums.size(); jj++) {
                if (nums[ii] + nums[jj] == target) {
                    sol[0] = (int)ii;
                    sol[1] = (int)jj;
                    return sol;
                }
            }
        }
        return sol;
    }
    
};

int main(int argc, const char * argv[]) {
    
    string data;
    // target, N, 1, 2, ... N numbers
    data = "9 4 2 7 11 15"; //
    stringstream ss(data);
    
    int target;
    int N;
    
    ss >> target;
    ss >> N;
    cout << "target: " << target << endl;
    cout << "N: " << N << endl;
    vector<int> A(N);
    for (int ii = 0; ii < N; ii++) {
        ss >> A[ii];
        cout << "[" << ii << "]: " << A[ii] << " " << endl;
    }

    Solution solution;
    vector<int> sol = solution.twoSum(A, target);
    cout << "solution: " << sol[0] << " " << sol[1] << endl;
    
    return 0;
}
