// https://leetcode.com/problems/power-of-two/
// Attempt 1: Using bitwise operations
// Outcome: Accepted
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n-1));
    }
};
