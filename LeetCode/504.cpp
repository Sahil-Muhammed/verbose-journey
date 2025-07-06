// https://leetcode.com/problems/single-element-in-a-sorted-array/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    void binSearch(vector<int> nums, int low, int high, int* ans){
        if (low == 0){
            if (nums[low] != nums[low+1]){
                *ans = nums[low];
                return;
            }
        }
        if (high == nums.size() - 1){
            if (nums[high-1] != nums[high]){
                *ans = nums[high];
                return;
            }
        }
        int mid = (low+high)/2;
        if (mid != 0 && mid != nums.size() - 1){
        if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
            *ans = nums[mid];
        }
        binSearch(nums, low, mid, ans);
        binSearch(nums, mid+1, high, ans);
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        // binSearch(nums, 0, nums.size() - 1, &ans);
        for (int i = 0; i < nums.size(); ++i){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
// Attempt 2: Binary search
// Outcome: Accepted
class Solution {
public:
    int binSearch(vector<int> nums, int low, int high){
        int ans = -1;
        if (low > high){
            return -1;
        }
        int mid = (low+high)/2;
        if (nums[mid] == nums[mid-1]){
            if ((high - mid) % 2 == 0)
                return binSearch(nums, low, mid - 2);
            else
                return binSearch(nums, mid + 1, high);
        }
        else if (nums[mid] == nums[mid+1]){
            if ((high - mid) % 2 == 0)
                return binSearch(nums, mid + 2, high);
            else{
                return binSearch(nums, low, mid - 1);
            }
        }
        else{
            return nums[mid];
        }
        return ans;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        else if (nums[0] != nums[1]){
            return nums[0];
        }
        else if (nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }
        int ans = binSearch(nums, 0, nums.size() - 1);
        return ans;
    }
};
