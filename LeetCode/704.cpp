// https://leetcode.com/problems/binary-search/
// Attempt 1: Binary search (iterative)
// Outcome: Accepted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] < target){
                low = mid+1;
            }
            else if (nums[mid] > target){
                high = mid-1;
            }
            else{
                index = mid;
                return index;
            }
        }
        return index;
    }
};
// Attempt 2: Binary Search (recursive)
// Outcome: Accepted
class Solution {
public:
    int binSearch(vector<int> nums, int low, int high, int target){
        if (low > high){
            return -1;
        }
        int mid = (low+high)/2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            return binSearch(nums, low, mid-1, target);
        }
        return binSearch(nums, mid+1, high, target);
    }
    int search(vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size() - 1, target);
    }
};
