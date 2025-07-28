// https://leetcode.com/problems/subsets/description/
// Attempt 1: Using binary representation to include and exclude arrays
// Outcome: Accepted
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int count = 0;
        vector<vector<int>> ans;
        int repeat = 1;
        for (int i = 0; i < nums.size(); ++i){
            repeat *= 2;
        }
        for (int i = 1; i <= repeat; ++i){
            vector<int> potentialAns;
            int tempCount = i;
            int index = 0;
            while (index < nums.size()){
                if ((tempCount&1) == 1){
                    potentialAns.push_back(nums[index]);
                }
                index++;
                tempCount = tempCount >> 1;
            }
            ans.push_back(potentialAns);
        }
        return ans;
    }
};
// Attempt 2: Using backtracking
// Outcome: Accepted
class Solution {
public:
    void recursivePowerset(vector<int>& nums, vector<int> ds, vector<vector<int>>& ans, int pos){
        ans.push_back(ds);
        for (int i = pos; i < nums.size(); ++i){
            ds.push_back(nums[i]);
            recursivePowerset(nums, ds, ans, i+1);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursivePowerset(nums, ds, ans, 0);
        return ans;
    }
};
