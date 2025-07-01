// https://leetcode.com/problems/3sum/
// Attempt 1: Brute force
// Outcome: 309/314; TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int low = 0, high = 1, sum = 0;
        vector<vector<int>> ans;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size() - 1; ++i){
            for (int j = i+1; j < nums.size(); ++j){
                if (i != j && hash.find(0 - nums[i] - nums[j]) != hash.end()){
                    vector<int> potential;
                    potential.push_back(0 - nums[i] - nums[j]);
                    potential.push_back(nums[i]);
                    potential.push_back(nums[j]);
                    ans.push_back(potential);
                }
            }
            hash[i] = nums[i];
        }
        return ans;
    }
};
// Attempt 2: Using a two pointer approach without sorting
// Outcome: 312/314; TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> sat;
        for (int i = 0; i < nums.size(); ++i){
            set<int> potential;
            for (int j = i + 1; j < nums.size(); ++j){
                if (potential.find(-(nums[i] + nums[j])) != potential.end()){
                    vector<int> oneAns = {nums[i], nums[j], -(nums[i] + nums[j])};
                    sort(oneAns.begin(), oneAns.end());
                    sat.insert(oneAns);
                }
                potential.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(sat.begin(), sat.end());
        return ans;
    }
};
// Attempt 3: Two pointer approach with sorting
// Outcome: Accepted
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i){
            int j = i + 1, k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            while (j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0){
                    j++;
                }
                else if (sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
