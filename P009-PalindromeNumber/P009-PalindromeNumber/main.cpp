//
//  LeetCode
//  Algorithm 9 Palindrome Number
//
//  Created by Rick Lan on 3/30/17.
//  See LICENSE
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x >= 0) {
            long long save = x;
            long long mag2 = 0;
            while (x) {
                int digit = x % 10;
                mag2 = mag2 * 10 + digit;
                x = x / 10;
            }
            return (save == mag2);
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int x;
    x = 0; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = 121; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -121; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = 321; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -321; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = 9999; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -9999; cout << x << ": " << solution.isPalindrome(x) << endl;
    
    x = 1987667891; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -1987667891; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = 2147447412; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -2147447412; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = -2147483648; cout << x << ": " << solution.isPalindrome(x) << endl;
    x = 1563847412; cout << x << ": " << solution.isPalindrome(x) << endl;
/*
 Input:
 -2147447412
 Output:
 true
 Expected:
 false
 
 
 -2147483648
 */
    return 0;
}
