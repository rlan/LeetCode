//
//  LeetCode
//  Algorithm 20 Valid Parentheses
//
//  Created by Rick Lan on 3/31/17.
//  See LICENSE
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    bool isPair(char lhs, char rhs) {
        switch (lhs) {
            case '[':
                if (rhs==']') return true;
                else return false;
            case '{':
                if (rhs=='}') return true;
                else return false;
            case '(':
                if (rhs==')') return true;
                else return false;
            default: return false;
        }
    }
    
    bool isValid(string s) {
        
        if (s.size() % 2)
            return false;
        if (s.size()==0)
            return true;
        
        stack<char> stack;
        for (unsigned int ii = 0; ii < s.size(); ii++) {
            switch (s[ii]) {
                case '[':
                case '{':
                case '(':
                    stack.push(s[ii]);
                    break;
                case ']':
                case '}':
                case ')':
                    if (stack.empty()) {
                        return false;
                    } else if (isPair(stack.top(), s[ii])) {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    return false;
                    break;
            }

        }
               
        return (stack.size() == 0);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    
    string s;
    bool sol;
    s = "["; sol = solution.isValid(s); // false
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "}"; sol = solution.isValid(s); // false
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "()"; sol = solution.isValid(s); // true
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "[](){}"; sol = solution.isValid(s); // true
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "([])"; sol = solution.isValid(s); // true
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "(]"; sol = solution.isValid(s); // false
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    s = "([)]"; sol = solution.isValid(s); // false
    cout << "'" << s << "' isValid " << (sol ? "true" : "false") << endl;
    return 0;
}
