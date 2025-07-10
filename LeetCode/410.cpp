// https://leetcode.com/problems/split-array-largest-sum/
// Attempt 1: Using binary search
// Outcome: Accepted
class Solution {
public:
    bool compute(vector<int> nums, int k, int lim){
        int j = 0, count = 0, sum = 0;
        while (j < nums.size()){
            sum += nums[j];
            if (sum > lim){
                sum = nums[j];
                count++;
            }
            j++;
        }
        cout << "Mid is " << lim << " and count is " << count << endl;
        if (count >= k){
            return true;
        }
        return false;
    }
    int binSearch(vector<int> nums, int k, int max){
        int low = max, high = INT_MAX;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (compute(nums, k, mid) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        int max = 0;
        //long long sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (max < nums[i]){
                max = nums[i];
            }
            //sum += nums[i];
        }
        return binSearch(nums, k, max);
    }
};