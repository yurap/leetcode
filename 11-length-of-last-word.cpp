// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (l == 0 && s[i] == ' ') continue;
            if (s[i] != ' ') ++l;
            if (l > 0 && s[i] == ' ') break;
        }
        return l;
    }
};
