// https://leetcode.com/problems/merge-intervals/description/
// Attempt 1: Use a single pass and separate returning array; check if last element is greater than iterating elements first part
// Outcome: Accepted
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int minNum = intervals[0][0];
        int left = 0, right = 0;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i][0] <= ans.back()[1]){
                ans[ans.size() - 1][1] = max(intervals[i][1], ans.back()[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
