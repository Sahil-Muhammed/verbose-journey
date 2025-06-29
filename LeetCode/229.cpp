// https://leetcode.com/problems/majority-element-ii/
// Attempt 1: Using a hashmap, store the count
// Outcome: Accepted
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> hash;
        int lim = (nums.size() / 3) + 1;
        for (int i = 0; i < nums.size(); ++i){
            hash[nums[i]] += 1;
            if (hash[nums[i]] == lim){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
// Attempt 2: Brute force
// Outcome: Accepted
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i){
            if (ans.empty() == true || nums[i] != ans[0]){
                int count = 0;
                for (int j = i; j < nums.size(); ++j){
                    if (nums[j] == nums[i]){
                        count++;
                    }
                }
                if (count > nums.size() / 3){
                    ans.push_back(nums[i]);
                }
            }
            if (ans.size() == 2){
                break;
            }
        }
        return ans;
    }
};
// Attempt 3: Moore's Voting Principle
// Outcome: Accepted
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1 = 0, count2 = 0;
        int el1 = 0, el2 = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (count1 == 0 && nums[i] != el2){
                count1 = 1;
                el1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != el1){
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1){
                count1++;
            }
            else if (nums[i] == el2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (el1 == nums[i]){
                count1++;
            }
            else if (el2 == nums[i]){
                count2++;
            }
        }
        if (count1 > nums.size() / 3){
            ans.push_back(el1);
        }
        if (count2 > nums.size() / 3){
            ans.push_back(el2);
        }
        return ans;
    }
};
