// https://leetcode.com/problems/house-robber-ii/
// Attempt 1: Using recursion
// Outcome: 53/75; MLE
class Solution {
public:
    int recursion(int pos, int endingPos, vector<int> nums){
        if (pos < endingPos){
            return 0;
        }
        if (pos == endingPos){
            return nums[pos];
        }
        return max(nums[pos] + recursion(pos - 2, endingPos, nums), recursion(pos - 1, endingPos, nums));
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int l = recursion(nums.size() - 1, 1, nums);
        int r = recursion(nums.size() - 2, 0, nums);
        return max(l, r);
    }
};
// Attempt 2: Using dynamic programming (memoization)
// Outcome: Accepted
class Solution {
public:
    int memo(int pos, int endingPos, vector<int> nums, vector<int>& dp){
        if (pos < endingPos){
            return 0;
        }
        if (pos == endingPos){
            return nums[pos];
        }
        if (dp[pos] != -1){
            return dp[pos];
        }
        return dp[pos] = max(nums[pos] + memo(pos - 2, endingPos, nums, dp), memo(pos - 1, endingPos, nums, dp));
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        vector<int> dp(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        int l = memo(nums.size() - 1, 1, nums, dp);
        int r = memo(nums.size() - 2, 0, nums, dp1);
        return max(l, r);
    }
};
// Attempt 3: Using dynamic programming (tabulation)
// Outcome: Accepted
class Solution {
public:
    int tabulation(vector<int> nums){
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        if (nums.size() > 1){
            dp[1] = max(nums[0], nums[1]);
        }
        for (int i = 2; i < nums.size() - 1; ++i){
            int left = nums[i] + dp[i - 2];
            int right = dp[i-1];
            dp[i] = max(left, right);
        }
        vector<int> dp1(nums.size(), -1);
        dp1[0] = nums[1];
        if (nums.size() > 2){
            dp1[1] = max(nums[2], nums[1]);
        }
        for (int i = 2; i < nums.size() - 1; ++i){
            int left = nums[i+1] + dp1[i-2];
            int right = dp1[i-1];
            dp1[i] = max(left, right);
        }
        return max(dp[nums.size() - 2], dp1[nums.size() - 2]);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        return tabulation(nums);
    }
};
// Attempt 4: Using dynamic programming (space optimized)
// Outcome: Accepted
class Solution {
public:
    int spaceOptimized(vector<int> nums){
        int prev1, prev2, curr;
        prev2 = nums[0];
        prev1 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; ++i){
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        int first = prev1;
        prev2 = nums[1];
        if (nums.size() > 2)
            prev1 = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size() - 1; ++i){
            curr = max(nums[i+1] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        int second = prev1;
        return max(first, second);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        return spaceOptimized(nums);
    }
};
