// https://leetcode.com/problems/sqrtx/

class Solution {
public:

    // both begin and end are included in candidates range
    int sqrtWithinRange(int begin, int end, int x) {
        if (begin == end) {
            return begin;            
        }
        
        if (begin + 1 == end) {
            if (x / end >= end) return end;
            return begin;
        }
        
        // always true: begin < middle < end
        int middle = (begin + end) / 2;

        // cannot just do a middle * middle
        // as overflow is possible
        int div = x / middle;
        int mod = x % middle;

        if (div == middle && mod == 0) {
            return middle;
        }

        if (div < middle) {
            return sqrtWithinRange(begin, middle - 1, x);
        }
            
        // if middle*middle < x - middle still can be the right answer
        return sqrtWithinRange(middle, end, x);
    }
    
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        return sqrtWithinRange(1, x/2, x);
    }
};
