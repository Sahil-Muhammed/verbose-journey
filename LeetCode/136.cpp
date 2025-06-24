// Link: https://leetcode.com/problems/single-number/description/
// Attempt 1: XOR all the values
// Accepted
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (int i = 0; i < nums.size(); ++i){
            val = val ^ nums[i];
        }
        return val;
    }
};
