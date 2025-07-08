// https://leetcode.com/problems/kth-missing-positive-number/description/
// Attempt 1: Binary search on hashmap containing missing number count at any index
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high){
            int mid = (low+high)/2;
            int missing = arr[mid] - (mid+1);
            if (missing < k){ // missing > k doesnt work for some testcases :o
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high+k+1;
    }
};
