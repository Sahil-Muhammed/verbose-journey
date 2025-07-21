// https://leetcode.com/problems/subsets-ii/description/
// Attempt 1: Iteratively adding elements and idea of binary representation for 2^n
// Outcome: Accepted
class Solution {
public:
    void recursiveTree(int index, vector<int> arr, vector<vector<int>>& ans){
        int twoPower = 1;
        for (int i = 0; i < arr.size(); ++i){
            twoPower *= 2;
        }

        for (int j = 0; j < twoPower; ++j){
            vector<int> ds;
            int temp = j;
            int index = 0;
            while (temp){
                if ((temp&1) == 1){
                    ds.push_back(arr[index]);
                }
                temp = temp >> 1;
                index++;
            }
            if (find(ans.begin(), ans.end(), ds) != ans.end()){
                continue;
            }
            ans.push_back(ds);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        recursiveTree(0, nums, ans);
        return ans;
    }
};
