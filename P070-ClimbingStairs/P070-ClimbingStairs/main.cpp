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
    
    int nChooseK(int n, int k) {
        //return factorial(n) / factorial(n-k) / factorial(k);
        
        if ((k==0)||(k==n))
            return 1;
        
        int large;
        int small;
        if (k >= n-k) {
            large = k;
            small = n-k;
        } else {
            large = n-k;
            small = k;
        }
        //cout << "L " << large << " S " << small << endl;
        
        unsigned long long ratio = n;
        unsigned long i = n-1;
        unsigned long j = 2;
        while (i >= large+1) {
            //cout << "ratio " << ratio << endl;
            ratio = ratio * i;
            i--;
            
            if (j <= small) {
                //cout << " ratio " << ratio << " j " << j << endl;
                ratio = ratio / j;
                j++;
            }
        }
        while (j <= small) {
            ratio = ratio / j;
            j++;
        }
        
        return ratio;
    }

    int climbStairs(int n) {
        int two_count = 0;
        int total = 0;
        while ((n - two_count*2) >= 0) {
            //int steps = n - two_count*2 + two_count;
            int steps = n - two_count;
            int perm = nChooseK(steps, two_count);
            //cout << "steps " << steps << " 2_count " << two_count << " perm " << perm << " total " << total << endl;
            total += perm;
            two_count++;
        }
        return total;
    }
};

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

int nCk(int n, int k) {
    return factorial(n) / factorial(n-k) / factorial(k);
}



void testSolution(void) {
    
    Solution solution;
    
    /*
    cout << "test factorial" << endl;
    for (unsigned long i = 0; i < 25; i++) {
        cout << "factorial(" << i << ") = " << factorial(i) << endl;
    }
     */
    
    cout << "test combo" << endl;
    //cout << nChooseK(7,0) << endl;
    //cout << nChooseK(7,3) << endl;
    //cout << nPermK(7,3) << endl;

    //cout << nPermK(24,11) << endl;
    //cout << nChooseK(24,11) << endl;

    cout << "test combo 2" << endl;
    for (unsigned long i = 0; i <= 13; i++) {
        cout << "i " << i;
        long ref = nCk(13,i);
        long x = solution.nChooseK(13,i);
        cout << " ref " << ref << " x " << x;
        
        if (ref != x) {
            cout << " ERROR" << endl;
        } else {
            cout << endl;
        }
    }

}



int main(int argc, const char * argv[]) {
    
    //testSolution();
    //return 0;
    
    Solution solution;
    for (int x = 1; x <= 9; x++) {
        int sol = solution.climbStairs(x);
        cout << "x " << x << " sol " << sol << endl;
    }
    
    int x;
    x = 35;
    int sol = solution.climbStairs(x);
    cout << "x " << x << " sol " << sol << endl;

    return 0;
}
