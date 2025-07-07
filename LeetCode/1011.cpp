// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
// Attempt 1: Binary search over answer space
// Outcome: Accepted
class Solution {
public:
    bool calcWeights(vector<int> nums, int days, int limit){
        int day = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (sum <= limit){
                continue;
            }
            else{
                day++;
                sum = nums[i];
                if (day > days){
                    return false;
                }
            }
        }
        if (sum <= limit){
            day++;
        }
        else{
            return false;
        }
        return day <= days;
    }
    int binSearch(vector<int> nums, int days, int max){
        int low = max, high = INT_MAX;
        while (low <= high){
            int mid = low + (high - low)/2;
            int val = calcWeights(nums, days, mid);
            cout << mid << " " << val << endl;
            if (val == true){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int max = 1;
        for (int i = 0; i < weights.size(); ++i){
            if (max < weights[i]){
                max = weights[i];
            }
        }
        return binSearch(weights, days, max);
    }
};
