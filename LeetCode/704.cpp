// https://leetcode.com/problems/binary-search/
// Attempt 1: Binary search
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
