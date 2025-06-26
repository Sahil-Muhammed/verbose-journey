// https://leetcode.com/problems/majority-element/description/
// Attempt 1: Sort the array, return the element which exceeds majority count
// Outcome: Accepted
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1, size = nums.size();
        for (int i = 1; i < size; ++i){
            if (nums[i] == nums[i-1]){
                count++;
                if (count > size/2){
                    return nums[i];
                }
            }
            else{
                count = 1;
            }
        }
        return nums[0];
    }
};
// Attempt 2: Another variant of sorting
// Outcome: Accepted
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};
// Attempt 3: Using a hashmap, store the frequency. While incrementing, check if it exceeds size/2.
// Outcome: Accepted
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); ++i){
            freq[nums[i]] += 1;
            if (freq[nums[i]] > nums.size()/2){
                return nums[i];
            }
        }
        return nums[0];
    }
};
// Attempt 4: Moore's Voting Algorithm
// Outcome: Accepted
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = nums[nums.size() - 1];
        for (int i = 0; i < nums.size(); ++i){
            if (count == 0){
                candidate = nums[i];
            }
            if (nums[i] == candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};
