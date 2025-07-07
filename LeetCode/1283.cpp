// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
// Attempt 1: Binary search over answer space
// Outcome: Accepted
class Solution {
public:
    bool calcThreshold(vector<int> nums, int threshold, int val){
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += ceil((double)nums[i] / val);
            if (sum > threshold){
                return false;
            }
        }
        return sum <= threshold;
    }
    int binSearch(vector<int> nums, int threshold, int min, int max){
        int low = min, high = max;
        while (low <= high){
            int mid = (low+high)/2;
            int val = calcThreshold(nums, threshold, mid);
            if (val == true){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = 1;
        for (int i = 0; i < nums.size(); ++i){
            if (max < nums[i]){
                max = nums[i];
            }
        }
        return binSearch(nums, threshold, 1, max);
    }
};
