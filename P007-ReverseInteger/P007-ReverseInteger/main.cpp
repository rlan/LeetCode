//
//  LeetCode
//  Algorithm 7 Reverse Integer
//
//  Created by Rick Lan on 3/30/17.
//  See LICENSE
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool positive;
        long long magnitude;
        
        if (x > 0) {
            positive = true;
            magnitude = x;
        } else {
            positive = false;
            magnitude = -(long long)(x);
        }
        
        long long mag2 = 0;
        while (magnitude) {
            int digit = magnitude % 10;
            mag2 = mag2 * 10 + digit;
            magnitude = magnitude / 10;
        }
        
        if (positive) {
            if (mag2 > ((1ULL<<31) - 1)) {
                return 0;
            } else {
                return (int)mag2;
            }
        } else {
            if (mag2 > (1ULL<<31)) {
                return 0;
            } else {
                return (int)(-mag2);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << "Expect -321: " << solution.reverse(-123) << endl; // expect -321
    cout << "Expect 321: " << solution.reverse(123) << endl; // expect 321
    cout << "Expect -123: " << solution.reverse(-321) << endl; // expect -123
    cout << "Expect 123: " << solution.reverse(321) << endl; // expect 123

    cout << "Expect 0: " << solution.reverse( 1534236469) << endl; // expect 0
    cout << "Expect 0: " << solution.reverse(-2147483648) << endl; // expect 0
    cout << "Expect 0: " << solution.reverse( 1563847412) << endl; // expect 0
    return 0;
}
