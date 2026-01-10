// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08
// Attempt 1: Using DP
// Outcome: Accepted; 69/69
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = 0; i <= nums1.size(); ++i){
            dp[i][nums2.size()] = -1000000;
        }
        for (int j = 0; j <= nums2.size(); ++j){
            dp[nums1.size()][j] = -1000000;
        }

        for (int i = nums1.size() - 1; i >= 0; --i){
            for (int j = nums2.size() - 1; j >= 0; --j){
                int temp1 = max(dp[i+1][j+1], (nums1[i]*nums2[j]) + dp[i+1][j+1]);
                int temp2 = max(nums1[i] * nums2[j], dp[i][j+1]);
                int temp3 = max(temp1, temp2);
                dp[i][j] = max(temp3, dp[i+1][j]);
            }
        }

        return dp[0][0];
    }
};
