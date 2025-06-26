// https://leetcode.com/problems/maximum-subarray/description/
// Attempt 1: Brute force; go over every possible subarray and find the sum.
// Outcome: 204/210; TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum = 0;
            for (int j = i; j < nums.size(); ++j){
                sum += nums[j];
                if (sum > maxSum){
                    maxSum = sum;
                }
            }
        }
        return maxSum;
    }
};
// Attempt 2: Kadane's Algorithm; reset the sum variable to 0 when its becomes negative, otherwise keep adding and check if it exceeds maxSum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (sum > maxSum){
                maxSum = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};
