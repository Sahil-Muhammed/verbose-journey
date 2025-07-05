// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pos = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == target){
                pos = i;
                break;
            }
        }
        return pos != -1 ? true : false;
    }
};
// Attemp 2: Binary search
// Outcome: Accepted
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pos = -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = (low+high) / 2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
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
        return false;
    }
};
