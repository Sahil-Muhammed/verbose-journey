// https://leetcode.com/problems/combination-sum/description/
// Attempt 1: Using recursion, changing target value on next call if current position element is less than or equal to target and picking the next element in the same call
// Outcome: Accepted
class Solution {
public:
    void recursiveTree(vector<int> candidates, vector<int> ds, vector<vector<int>>& ans, int pos, int target){
        if (pos == candidates.size()){
            if (target == 0){
                (ans).push_back(ds);
            }
            return;
        }

        if (candidates[pos] <= target){
            ds.push_back(candidates[pos]);
            recursiveTree(candidates, ds, ans, pos, target - candidates[pos]);
            ds.pop_back();
        }

        recursiveTree(candidates, ds, ans, pos+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursiveTree(candidates, ds, ans, 0, target);
        return ans;
    }
};
// Attempt 2: Using recursion like previous method, but with a sum parameter as well
// Outcome: Accepted
class Solution {
public:
    void recursiveTree(vector<int> candidates, vector<int> ds, vector<vector<int>>& ans, int pos, int sum, int target){
        if (pos == candidates.size()){
            if (target == sum){
                (ans).push_back(ds);
            }
            return;
        }

        if (sum > target){
            return;
        }

        if ((sum + candidates[pos]) <= target){
            ds.push_back(candidates[pos]);
            recursiveTree(candidates, ds, ans, pos, sum + candidates[pos], target);
            ds.pop_back();
        }

        recursiveTree(candidates, ds, ans, pos+1, sum, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursiveTree(candidates, ds, ans, 0, 0, target);
        return ans;
    }
};
