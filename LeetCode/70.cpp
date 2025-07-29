// https://leetcode.com/problems/climbing-stairs/description/
// Attempt 1: Using basic recursion
// Outcome: 21/45; TLE
class Solution {
public:
    void recursion(int pos, int* count, vector<int>& dp){
        if (pos < 0){
            return;
        }
        if (pos == 0){
            *count = *count + 1;
            return;
        }
        recursion(pos-1, count);
        recursion(pos-2, count);
    }
    int climbStairs(int n) {
        int count = 0;
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        recursion(n, &count, dp);
        return count;
    }
};
// Attempt 2: Using DP
// Outcome: Accepted
class Solution {
public:
    int recursion(int pos, vector<int>& dp){
        if (pos <= 2) return pos;
        if (dp[pos] != 0) return dp[pos]; 
        return dp[pos] = recursion(pos-1, dp) + recursion(pos-2, dp);
    }
    int climbStairs(int n) {
        int count = 0;
        vector<int> dp(n+1, 0);
        return recursion(n, dp);
    }
};
