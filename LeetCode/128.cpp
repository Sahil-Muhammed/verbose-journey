// https://leetcode.com/problems/longest-consecutive-sequence/description/
// Attempt 1: Sort and count longest sequence
// Outcome: Accepted
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1 || nums.size() == 0){
            return nums.size();
        }
        int len = 1, maxLen = 0;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] == nums[i-1] + 1){
                len++;
                maxLen = max(maxLen, len);
            }
            else if (nums[i] == nums[i-1]){
                maxLen = max(maxLen, len);
            }
            else{
                len = 1;
            }
        }
        return maxLen;
    }
};
// Attempt 2: Use a set data structure to store and check
// Outcome: Accepted
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 0){
            return nums.size();
        }
        int maxLen = 0;
        unordered_set<int> set1(nums.begin(), nums.end());
        for (int num : set1){
            if (set1.find(num - 1) == set1.end()){
                int j = num, len = 1;
                while(set1.find(j+1) != set1.end()){
                    len++;
                    j++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
