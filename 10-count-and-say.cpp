// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string generateNext(const string& seq) {
        string next;
        int counter = 1;
        for (int i = 1; i < seq.size(); ++i) {
            if (seq[i] == seq[i - 1]) {
                ++counter;
            } else {
                next += to_string(counter) + seq[i - 1];
                counter = 1;
            }
        }
        next += to_string(counter) + seq[seq.size() - 1];
        return next;
    }
    
    string countAndSay(int n) {
        string seq = "1";
        for (int i = 0; i < n - 1; ++i) {
            seq = generateNext(seq);
        }
        return seq;
    }
};
