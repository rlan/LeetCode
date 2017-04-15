//
//  main.cpp
//  P067-AddBinary
//
//  Created by Rick Lan on 4/15/17.
//  See LICENSE
//

#include <iostream>
#include <string>

using namespace std;


unsigned long binaryToInt(string s) {
    unsigned long mask = 1;
    unsigned long value = 0;
    for (long i = s.size()-1; i >= 0; i--) {
        if (s[i]=='1') {
            value |= mask;
        }
        mask <<= 1;
    }
    return value;
}

string uintToString(unsigned long x) {
    
    if (x==0)
        return "0";
    
    string ret = "";
    while (x) {
        ret.insert(ret.begin(), (x & 0x1 ? '1' : '0'));
        x >>= 1;
    }
    return ret;
}

class Solution {
public:
    string addBinary(string a, string b) {
        
        if (a.size() < b.size())
            return addBinary(b,a);


        // a.size >= b.size
        bool carry = false;
        
        long a_i = a.size()-1;
        long b_i = b.size()-1;
        
        while (carry || (b_i >= 0)) {
            
            if (b_i >= 0) {
                bool sum = (a[a_i]=='1') ^ (b[b_i]=='1') ^ carry;
                carry = ((a[a_i]=='1') & (b[b_i]=='1')) | ((b[b_i]=='1') & carry) | ((a[a_i]=='1') & carry);
                a[a_i] = sum ? '1' : '0';
            } else if (carry) {
                if (a_i >= 0) {
                    bool sum = (a[a_i]=='1') ^ carry;
                    carry = (a[a_i]=='1') & carry;
                    a[a_i] = sum ? '1' : '0';
                } else {
                    a.insert(a.begin(), '1');
                    carry = false;
                }
            }
            a_i--;
            b_i--;
        }
        
        return a;
    }
};


int main(int argc, const char * argv[]) {

    string a;
    string b;
    
    //a = "111"; b = "1";
    //a = "1"; b = "1111";
    a = "1010"; b = "1011";
    
    
    unsigned long int_a = binaryToInt(a);
    unsigned long int_b = binaryToInt(b);
    unsigned long int_s = int_a + int_b;
    string s = uintToString(int_s);
    
    cout << "a [" << a << "] " << int_a << endl;
    cout << "b [" << b << "] " << int_b << endl;
    cout << "sum [" << s << "] " << int_s << endl;
    
    Solution solution;
    string sol = solution.addBinary(a, b);
    cout << "Sol [" << sol << "]" << endl;
    return 0;
}
