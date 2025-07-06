// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[min] > nums[i]){
                min = i;
            }
        }
        return nums[min];
    }
};
// Attempt 2: Use binary search to reduce the searching space over the UNSORTED subarray
// Outcome: Accepted
class Solution {
public:
    int minBinSearch(vector<int> arr){
        int ans = arr[0];
        int low = 0, high = arr.size() - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (arr[mid] > arr[high]){
                ans = min(ans, arr[high]);
                low = mid + 1;
            }
            else{
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
    int findMin(vector<int>& nums) {
        return minBinSearch(nums);
    }
};
