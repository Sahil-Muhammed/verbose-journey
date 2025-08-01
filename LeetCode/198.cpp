// https://leetcode.com/problems/house-robber/description/
// Attempt 1: Using recursion, maximum of i - 2 path and i - 3 path
// Outcome: 55/70; MLE
class Solution {
public:
    int recursion(int pos, vector<int> nums){
        if (pos < 0){
            return 0;
        }
        if (pos == 0 || pos == 1){
            return nums[pos];
        }
        int path1 = nums[pos] + recursion(pos - 2, nums);
        int path2 = nums[pos] + recursion(pos - 3, nums);
        return max(path1, path2);
    }
    int rob(vector<int>& nums) {
        int l = recursion(nums.size() - 1, nums);
        int sl = recursion(nums.size() - 2, nums);
        return max(l, sl);
    }
};
// Attempt 2: Using dynamic programming (memoization)
// Outcome: Accepted
class Solution {
public:
    int memo(int pos, vector<int> nums, vector<int>& dp){
        if (pos < 0){
            return 0;
        }
        if (pos == 0 || pos == 1){
            return nums[pos];
        }
        if (dp[pos] != -1){
            return dp[pos];
        }
        int path1 = nums[pos] + memo(pos - 2, nums, dp);
        int path2 = nums[pos] + memo(pos - 3, nums, dp);
        return dp[pos] = max(path1, path2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int l = memo(nums.size() - 1, nums, dp);
        vector<int> dp1(nums.size(), -1);
        int r = memo(nums.size() - 2, nums, dp1);
        return max(l, r);
    }
};
// Attempt 3: Using dynamic programming (tabulation)
// Outcome: Accepted
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        dp[0] = nums[0];
        if (nums.size() > 1){
            dp[1] = nums[1];
        }
        for (int i = 2; i < nums.size(); ++i){
            int path1 = nums[i] + dp[i - 2];
            int path2 = 0;
            if (i > 2){
                path2 = nums[i] + dp[i-3];
            }
            dp[i] = max(path1, path2);
        }
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        for (int i = 2; i < nums.size() - 1; ++i){
            int path1 = nums[i] + dp1[i - 2];
            int path2 = 0;
            if (i > 2){
                path2 = nums[i] + dp1[i-3];
            }
            dp1[i] = max(path1, path2);
        }
        return max(dp[nums.size() - 1], dp1[nums.size() - 2]);
    }
};
// Attempt 4: Using dynamic programming (space optimization)
// Outcome: Accepted
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int prev1, prev2, currL;
        prev2 = 0;
        prev1 = 0;
        for (int i = 0; i < nums.size(); ++i){
            currL = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = currL;
        }
        return prev1;
    }
};
