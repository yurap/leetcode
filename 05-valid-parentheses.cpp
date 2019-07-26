// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isOpeningBracket(char c) {
        return c == '(' || c == '{' || c == '[';
    }

    bool checkBracketsArePair(char opening, char closing) {
        return
            (opening == '(' && closing == ')')
            || (opening == '[' && closing == ']')
            || (opening == '{' && closing == '}');
    }
    
    bool isValid(string s) {
        stack<char> hist;
        for (auto c: s) {
            if (isOpeningBracket(c)) {
                hist.push(c);
                continue;
            }
            if (hist.size() > 0 && checkBracketsArePair(hist.top(), c)) {
                hist.pop();
                continue;
            }
            return false;
        }
        
        return hist.size() == 0;
    }
};
