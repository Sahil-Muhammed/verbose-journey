// https://leetcode.com/problems/missing-number/
// Missing number
// Attempt 1: Subtract sum of n numbers from the sum of all elements from the array
// Outcome: Accepted
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long num = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i){
            num += nums[i];
        }
        long long big = (size * (size + 1)) / 2;
        int ans = (int)big - num;
        return ans;
    }
};
