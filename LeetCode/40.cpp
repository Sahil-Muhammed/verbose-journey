// https://leetcode.com/problems/combination-sum-ii/
// Attempt 1: Using recursion, sorting before passing to auxiliary function, and checking for duplicate answers before pushing to answer array
// Outcome: Memory exceeded
class Solution {
public:
    void recursiveTree(int pos, int sum, int target, vector<int>& ds, vector<int> candidates, vector<vector<int>>& ans){
        if (sum > target){
            return;
        }
        if (pos == candidates.size()){
            if (sum == target && find(ans.begin(), ans.end(), ds) == ans.end()){
                ans.push_back(ds);
            }
            return;
        }

        ds.push_back(candidates[pos]);
        recursiveTree(pos+1, sum + candidates[pos], target, ds, candidates, ans);
        ds.pop_back();
        recursiveTree(pos+1, sum, target, ds, candidates, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        recursiveTree(0, 0, target, ds, candidates, ans);
        return ans;
    }
};
