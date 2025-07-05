// https://leetcode.com/problems/maximum-product-subarray/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i){
            int mult = 1;
            for (int j = i; j < nums.size(); ++j){
                mult *= nums[j];
                max = mult > max ? mult : max;
            }
        }
        return max;
    }
};
// Attempt 2: Prefix and suffix multiplications
// Outcome: Accepted
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, suf = 1, pre = 1;
        for (int i = 0; i < nums.size(); ++i){
            if (pre == 0){
                pre = 1;
            }
            if (suf == 0){
                suf = 1;
            }
            pre *= nums[i];
            suf *= nums[nums.size() - 1 - i];
            maxi = max(maxi, max(pre, suf));
        }
        return maxi;
    }
};
