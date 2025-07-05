// https://leetcode.com/problems/search-insert-position/description/
// Attempt 1: Upper bound approach (recursive)
// Accepted
class Solution {
public:
    int upBound(vector<int> nums, int low, int high, int target){
        if (low > high){
            return low;
        }
        int mid = (low+high)/2;
        if (nums[mid] > target){
            return upBound(nums, low, mid-1, target);
        }
        else if (nums[mid] < target){
            return upBound(nums, mid+1, high, target);
        }
        else{
            return mid;
        }
        return mid;
    }
    int searchInsert(vector<int>& nums, int target) {
        return upBound(nums, 0, nums.size() - 1, target);
    }
};
