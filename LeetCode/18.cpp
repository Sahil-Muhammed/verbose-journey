// https://leetcode.com/problems/4sum/description/
// Attempt 1: Using a two pointer approach with sorting
// Outcome: Accepted
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for (int j = i + 1; j < nums.size(); ++j){
                int k = j + 1, l = nums.size() - 1;
                if (j > i + 1 && nums[j] == nums[j-1]){
                    continue;
                }
                while (k < l){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum < target){
                        k++;
                    }
                    else if (sum > target){
                        l--;
                    }
                    else{
                        vector<int> temp;
                        temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while (k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
