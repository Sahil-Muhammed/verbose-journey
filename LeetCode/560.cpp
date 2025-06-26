// https://leetcode.com/problems/subarray-sum-equals-k/description/
// Attempt 1: Use a map to find the prefix sum
// Outcome: Accepted
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> storePairs;
       storePairs[0] = 1;
       int sum = 0, count = 0, rem = 0;
       for (int i = 0; i < nums.size(); ++i){
        sum += *(nums.begin() + i);
        rem = sum - k;
        count += storePairs[rem];
        storePairs[sum] += 1;
       }
       return count;
    }
};

// Attempt 2: Brute force; go over every possible subarray and check if its sum is k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count = 0, sum = 0;
       for (int i = 0; i < nums.size(); ++i){
        sum = 0;
        for (int j = i; j < nums.size(); ++j){
            sum += *(nums.begin() + j);
            if (sum == k){
                count++;
            }
        }
       }
       return count;
    }
};
