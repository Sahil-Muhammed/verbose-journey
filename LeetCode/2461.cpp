// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// Attempt 1: Sliding window with hashmap for storing frequency
// Outcome: Accepted
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        long long maxSum = 0, sum = 0;
        int flag = 0;
        for (int i = 0; i < k; ++i){
            hashmap[nums[i]] += 1;
            sum += nums[i];
            if (hashmap[nums[i]] == 1 && flag == 0){
                maxSum = max(maxSum, sum);
            }
            else{
                maxSum = 0;
                flag = 1;
                continue;
            }
        }

        for (int i = k; i < nums.size(); ++i){
            hashmap[nums[i-k]] -= 1;
            if (hashmap[nums[i-k]] == 0) {
                hashmap.erase(nums[i-k]);
            }
            hashmap[nums[i]] += 1;
            sum += nums[i] - nums[i-k];
            
            if (hashmap.size() == k){
                maxSum = max(maxSum, sum);
            }
            else{
                continue;
            }
        }
        return maxSum;
    }
};
