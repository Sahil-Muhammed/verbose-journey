// https://leetcode.com/problems/find-peak-element/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = -1;
        if (nums.size() == 1){
            return 0;
        }
        if (nums[0] > nums[1]){
            return 0;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2]){
            return nums.size() - 1;
        }
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > nums[(i-1) % nums.size()] && nums[i] > nums[(i+1) % nums.size()]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
// Attempt 2: Binary Search
// Outcome: Accepted
class Solution {
public:
    int binSearch(vector<int> nums, int low, int high){
        if (low > high){
            return -1;
        }
        int mid = (low + high) / 2;
        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
            return mid;
        }
        if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]){
            return binSearch(nums, mid+1, high);
        }
        else if (nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]){
            return binSearch(nums, low, mid-1);
        }
        else{
            if (nums[mid-1] > nums[mid+1]){
                return binSearch(nums, low, mid-1);
            }
            else{
                return binSearch(nums, mid+1, high);
            }
        }
        return 0;
    }
    int findPeakElement(vector<int>& nums) {
        int ans = -1;
        if (nums.size() == 1){
            return 0;
        }
        if (nums[0] > nums[1]){
            return 0;
        }
        if (nums[nums.size() - 1] > nums[nums.size() - 2]){
            return nums.size() - 1;
        }
        return binSearch(nums, 1, nums.size() - 2);
    }
};
