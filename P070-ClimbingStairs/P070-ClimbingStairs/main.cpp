//
//  main.cpp
//  P070-ClimbingStairs
//
//  Created by Rick Lan on 4/15/17.
//  Copyright © 2017 RickLan. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    
    // n >= 21 overflows
    unsigned long long factorial(int n) {
        
        if (n <= 1)
            return 1;
        else
            return n*factorial(n-1);
    }

    int nPermK(int n, int k) {
        return factorial(n) / factorial(n-k);
    }
    
    int nChooseK(int n, int k) {
        return nPermK(n, k) / factorial(k);
    }

    int climbStairs(int n) {
        int two_count = 0;
        int total = 0;
        while ((n - two_count*2) >= 0) {
            int steps = n - two_count*2 + two_count;
            int perm = nChooseK(steps, two_count);
            cout << "steps " << steps << " 2_count " << two_count << " perm " << perm << " total " << total << endl;
            total += perm;
            two_count++;
        }
        return total;
    }
};

void testSolution(void) {
    
    Solution solution;
    
    cout << "test factorial" << endl;
    for (unsigned long i = 0; i < 25; i++) {
        cout << "factorial(" << i << ") = " << solution.factorial(i) << endl;
    }
    
    cout << "test combo" << endl;
    //cout << solution.nChooseK(7,0) << endl;
    //cout << solution.nChooseK(7,3) << endl;
    //cout << solution.nPermK(7,3) << endl;

    cout << solution.nPermK(24,11) << endl;
    cout << solution.nChooseK(24,11) << endl;
    
}



int main(int argc, const char * argv[]) {
    
    testSolution();
    return 0;
    
    Solution solution;
    for (int x = 1; x <= 6; x++) {
        int sol = solution.climbStairs(x);
        cout << "x " << x << " sol " << sol << endl;
    }
    
    int x;
    x = 35;
    int sol = solution.climbStairs(x);
    cout << "x " << x << " sol " << sol << endl;

    return 0;
}
