// https://leetcode.com/problems/longest-increasing-subsequence/description/
// Attempt 1: Brute force
// Outcome: TLE
class Solution {
public:
    int LIS(int prev, int index, int currSize, vector<int>& arr){
        if (index >= arr.size()){
            return currSize;
        }
        if (prev >= arr[index]) return LIS(prev, index+1, currSize, arr);

        else{
            int skip = LIS(prev, index+1, currSize, arr);
            int take = LIS(arr[index], index+1, currSize+1, arr);
            return max(skip, take);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0;
        int currLen = 1;

        // brute force; cover all possibilities; start from a single element, check all increasing subsequence from that element

        int prev = nums[0];
        for (int i = 0; i < nums.size(); ++i){
            currLen = LIS(nums[i], i, 1, nums);
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};
// Attempt 2: Using 2D DP, memoization
// Outcome: Accepted
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

        // dp[i][j] --> denotes i as the current index and j is the index of the last element of our subsequence

        // j denotes index j - 1 of the array so that j = 0 means we have not chosen an element in our subsequence 

        // if i <= j, then dp[i][j] = INT_MIN
        // otherwise, in case nums[i] > nums[j], then dp[i][j] = max{dp[i+1][j], dp[i+1][i]} 
        // but, in case nums[i] <= nums[j], then dp[i][j] = dp[i+1][j] (skip)

        // base case

        for (int i = 0; i <= nums.size(); ++i){
            dp[nums.size()][i] = 0;
        }

        for (int i = nums.size() - 1; i > -1; --i){
            for (int j = nums.size(); j > -1; --j){
                if (j == 0 || nums[i] > nums[j-1]){
                    dp[i][j] = max(dp[i+1][j], 1 + dp[i+1][i+1]);
                }
                else{
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }
}; 
