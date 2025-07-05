// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pos = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == target){
                pos = i;
                break;
            }
        }
        return pos;
    }
};
// Attempt 2: Binary search
// Outcome: Accepted
class Solution {
public:
    int binSearch(vector<int> nums, int low, int high, int target){
        if (low > high)
            return -1;
        int mid = (low+high)/2;
        if (nums[mid] > target){
            return binSearch(nums, low, mid-1, target);
        }
        else if (nums[mid] < target){
            return binSearch(nums, mid+1, high, target);
        }
        return mid;
    }
    int binSearchforK(vector<int> nums){
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] > nums[nums.size() - 1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
    int search(vector<int>& nums, int target) {
        int pos = binSearchforK(nums);
        int index = 0, v1 = 0, v2 = 0;
        v1 = binSearch(nums, 0, pos-1, target);
        v2 = binSearch(nums, pos, nums.size() - 1, target);
        cout << pos << " " <<  v1 << " " << v2;
        index = max(v1, v2);
        return index;
    }
};
// Attempt 3:
// Outcome: Accepted
class Solution {
public:
    int binSearchforK(vector<int> nums, int target){
        int ans = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low+high)/2;
            if (nums[mid] == target){
                return mid;
            }
            if (nums[low] <= nums[mid]){
                if (nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if (nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pos = binSearchforK(nums, target);
        return pos;
    }
};
