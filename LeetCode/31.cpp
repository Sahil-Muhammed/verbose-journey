// https://leetcode.com/problems/next-permutation/description/
// Attempt 1: in-built STL function to generate next next permutation
// Outcome: Accepted
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
// Attempt 2: Find the breakpoint, find the smallest number greater than the breakpoint number, swap them, and sort
// Outcome: Accepted
class Solution {
public:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int index = -1, i = nums.size() - 2;
        for (i = nums.size() - 2; i > -1; --i){
            if (nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if (index == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        int minNumIndex = index+1;
        for (int j = index+1; j < nums.size(); ++j){
            if (nums[j] < nums[minNumIndex] && nums[j] > nums[index]){
                minNumIndex = j;
            }
        }
        swap(&nums[index], &nums[minNumIndex]);
        sort(nums.begin() + index + 1, nums.end());
    }
};
