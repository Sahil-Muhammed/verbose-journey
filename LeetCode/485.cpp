// https://leetcode.com/problems/max-consecutive-ones/description/
// Max Consecutive Ones
// Attempt 1: Keep two variables to keep track of current count of 1s and the highest count of 1s accordingly. Update only when 0 is faced or when you reach the end.
// Accepted
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 1 || (i == nums.size() - 1 && nums[i] == 1)){
                count++;
            }
            else if (nums[i] == 0){
                if (maxCount < count){
                    maxCount = count;
                }
                count = 0;
            }
        }
        if (maxCount < count){
            maxCount = count;
        }
        return maxCount;
    }
};

// Attempt 2: Update the return variable whenever the current count is incremented
// Accepted
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 1){
                count++;
                if (maxCount < count){
                    maxCount = count;
                }
            }
            else{
                count = 0;
            }
        }
        return maxCount;
    }
};
// Attempt 3: Sliding window technique
// Accepted
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right){
            if (nums[right] == 0){
                left = right + 1;
            }
            else{
                maxCount = max(maxCount, right - left + 1);
            }
        }
        return maxCount;
    }
};
