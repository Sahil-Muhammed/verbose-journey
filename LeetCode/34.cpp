// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, second = -1;
        int low = 0, high = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == target && first == -1){
                first = second = i;
            }
            else if (nums[i] == target && first != -1){
                second = i;
            }
        }
        return {first, second};
    }
};
// Attempt 2: Using lower bound and upper bound
// Outcome: Accepted
class Solution {
public:
    int lowerBound(vector<int> nums, int target){
        int ans = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int> nums, int target){
        int ans = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] > target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lowerBound(nums, target);
        int high = upperBound(nums, target);
        cout << low << endl;
        if (low == nums.size() || nums[low] != target){
            return {-1, -1};
        }
        return {low, high-1};
    }
};
