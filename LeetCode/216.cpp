// https://leetcode.com/problems/combination-sum-iii/description/
// Attempt 1: Using backtracking
// Outcome: Accepted
class Solution {
public:
    void recursiveTree(int pos, int k, int target, vector<int> ds, vector<vector<int>>& ans){
        if (ds.size() == k){
            if (target == 0 && find(ans.begin(), ans.end(), ds) == ans.end()){
                ans.push_back(ds);
            }
            return;
        }

        for (int i = pos; i <= 9; ++i){
            if (i > target){
                break;
            }
            ds.push_back(i);
            recursiveTree(i+1, k, target - i, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursiveTree(1, k, n, ds, ans);
        return ans;
    }
};
