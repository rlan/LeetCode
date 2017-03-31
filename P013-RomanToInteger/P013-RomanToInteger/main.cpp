//
//  LeetCode
//  Algorithm 13 Roman To Integer
//
//  Created by Rick Lan on 3/31/17.
//  See LICENSE
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int letterToValue(char c) {
        switch (c) {
            case 'I':
            case 'i':
                return 1;
            case 'V':
            case 'v':
                return 5;
            case 'X':
            case 'x':
                return 10;
            case 'L':
            case 'l':
                return 50;
            case 'C':
            case 'c':
                return 100;
            case 'D':
            case 'd':
                return 500;
            case 'M':
            case 'm':
                return 1000;
            default:
                return 0;
        }
    }
    
    int romanToInt(string s) {

        unsigned long N = s.size();
        if (N==0)
            return 0;
        
        int sol = 0;
        unsigned long ii = 1;
        int prev_digit = letterToValue(s[0]);
        int digit;
        int accum = prev_digit;
        
        while (ii < N) {
            digit = letterToValue(s[ii++]);
            if (digit > prev_digit) {
                sol += digit - accum;
                accum = 0;
            } else if (digit < prev_digit) {
                sol += accum;
                accum = digit;
            } else {
                accum += digit;
            }
            prev_digit = digit;
        }
        sol += accum;
        return sol;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    string s;
    s = ""; cout << s << " 0 " << solution.romanToInt(s) << endl;
    s = "III"; cout << s << " 3 " << solution.romanToInt(s) << endl;
    s = "IV"; cout << s << " 4 " << solution.romanToInt(s) << endl;
    s = "V"; cout << s << " 5 " << solution.romanToInt(s) << endl;
    s = "VI"; cout << s << " 6 " << solution.romanToInt(s) << endl;
    s = "XIX"; cout << s << " 19 " << solution.romanToInt(s) << endl;
    s = "LXVIII"; cout << s << " 68 " << solution.romanToInt(s) << endl;
    s = "DCCCXC"; cout << s << " 890 " << solution.romanToInt(s) << endl;
    s = "MDCCC"; cout << s << " 1800 " << solution.romanToInt(s) << endl;
    s = "MDCLXVI"; cout << s << " 1666 " << solution.romanToInt(s) << endl;
    cout << endl;
    s = "XC"; cout << s << " 90 " << solution.romanToInt(s) << endl;
    s = "XCI"; cout << s << " 91 " << solution.romanToInt(s) << endl;
    s = "XCII"; cout << s << " 92 " << solution.romanToInt(s) << endl;
    s = "XCIII"; cout << s << " 93 " << solution.romanToInt(s) << endl;
    s = "XCIV"; cout << s << " 94 " << solution.romanToInt(s) << endl;
    s = "XCV"; cout << s << " 95 " << solution.romanToInt(s) << endl;
    s = "XCVI"; cout << s << " 96 " << solution.romanToInt(s) << endl;
    s = "XCVII"; cout << s << " 97 " << solution.romanToInt(s) << endl;
    s = "XCVIII"; cout << s << " 98 " << solution.romanToInt(s) << endl;
    s = "XCIX"; cout << s << " 99 " << solution.romanToInt(s) << endl;
    return 0;
}
