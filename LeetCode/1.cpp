// https://leetcode.com/problems/two-sum/
// Attempt 1: Use a map to store the sums and check sum - i
// Outcome: Accepted
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> storeSum;
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum = target - *(nums.begin() + i);
            if (storeSum.find(sum) != storeSum.end()){
                ans.push_back(storeSum[sum]);
                ans.push_back(i);
            }
            storeSum[*(nums.begin() + i)] = i;
        }
        return ans;
    }
};
// Attempt 2: Brute force; go over every possible combination of two indices
// Outcome: Accepted
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size()-1; ++i){
            for (int j = i+1; j < nums.size(); ++j){
                int sum = *(nums.begin() + i) + *(nums.begin() + j);
                if (sum == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
