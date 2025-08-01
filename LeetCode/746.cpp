// https://leetcode.com/problems/min-cost-climbing-stairs/description/
// Attempt 1: Using recursion
// Outcome: 259/285; TLE
class Solution {
public:
    int minCost(int pos, vector<int> cost){
        if (pos < 0){
            return 1000;
        }
        if (pos == 0 || pos == 1){
            return cost[pos];
        }
        int left = cost[pos] + minCost(pos-1, cost);
        int right = cost[pos] + minCost(pos-2, cost);
        return min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int secondLast = minCost(cost.size() - 2, cost);
        int Last = minCost(cost.size() - 1, cost);
        return min(Last, secondLast);
    }
};
// Attempt 2: Using dynamic programming (memoization)
// Outcome: Accepted
class Solution {
public:
    int minCost(int pos, vector<int> cost, vector<int>& dp){
        if (pos < 0){
            return 1000;
        }
        if (pos == 0 || pos == 1){
            return cost[pos];
        }
        if (dp[pos] != -1){
            return dp[pos];
        }
        int left = cost[pos] + minCost(pos-1, cost, dp);
        int right = cost[pos] + minCost(pos-2, cost, dp);
        return dp[pos] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        int secondLast = minCost(cost.size() - 2, cost, dp);
        vector<int> dp1(cost.size(), -1);
        int Last = minCost(cost.size() - 1, cost, dp1);
        return min(Last, secondLast);
    }
};
// Attempt 3: Using dynamic programming (tabulation)
// Outcome: Accepted
class Solution {
public:
    int minCost(int pos, vector<int> cost, vector<int>& dp){
        if (pos < 0){
            return 1000;
        }
        if (pos == 0 || pos == 1){
            return cost[pos];
        }
        if (dp[pos] != -1){
            return dp[pos];
        }
        int left = cost[pos] + minCost(pos-1, cost, dp);
        int right = cost[pos] + minCost(pos-2, cost, dp);
        return dp[pos] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        vector<int> dp1(cost.size(), -1);

        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); ++i){
            int path1 = cost[i] + dp[i-1];
            int path2 = cost[i] + dp[i-2];
            dp[i] = min(path1, path2);
        }
        dp1[0] = cost[0];
        dp1[1] = cost[1];
        for (int i = 2; i < cost.size() - 1; ++i){
            int path1 = cost[i] + dp1[i-1];
            int path2 = cost[i] + dp1[i-2];
            dp1[i] = min(path1, path2);
        }
        return min(dp[cost.size() - 1], dp1[cost.size() - 2]);
    }
};
// Attempt 4: Using dynamic programming (space optimized)
// Outcome: Accepted
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1, prev2, currL;
        prev2 = cost[0];
        prev1 = cost[1];
        for (int i = 2; i < cost.size(); ++i){
            int path1 = cost[i] + prev1;
            int path2 = cost[i] + prev2;
            currL = min(path1, path2);
            prev2 = prev1;
            prev1 = currL;
        }
        return min(prev2, prev1);
    }
};
