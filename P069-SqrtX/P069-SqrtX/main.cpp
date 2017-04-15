//
//  LeetCode
//  Algorithm 69 Sqrt(x)
//
//  Created by Rick Lan on 4/15/17.
//  See LICENSE
//

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return INT_MIN;
        
        int t = x;
        int count = 0;
        while (t) {
            count++;
            t >>= 1;
        }
        count = (count/2) + (count%2);
        
        
        long mask = 1UL << (count-1);
        long value = 0;
        while (count--) {
            long sqr = (value|mask)*(value|mask);
            if (sqr == x) {
                return value|mask;
            } else if (sqr < x) {
                value |= mask;
            }
            mask >>= 1;
        }
        
        return value;
        
    }
};

int main(int argc, const char * argv[]) {
    
    int x;
    
    //x = -1;
    //x = 0;
    //x = 7;
    x = 2147395599;
    
    Solution solution;
    int sol = solution.mySqrt(x);
    cout << "x " << x << " sol " << sol << endl;
    return 0;
}
