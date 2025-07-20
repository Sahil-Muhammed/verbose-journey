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
