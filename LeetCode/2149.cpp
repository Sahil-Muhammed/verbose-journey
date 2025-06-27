// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Attempt 1: Two pointer approach; pointers at beginning and end
// Outcome: Didn't pass example test case :(
class Solution {
public:
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            if (nums[left] > 0){
                if (left%2 == 0){
                    left++;
                    continue;
                }
                else{
                    swap(&nums[left], &nums[right]);
                    continue;
                }
            }
            else{
                if (left%2 == 0){
                    swap(&nums[left], &nums[right]);
                    continue;
                }
                else{
                    left++;
                }
            }
        }
        return nums;
    }
};
// Attempt 2: Brute force; store positive and negative numbers in separate arrays and merge them accordingly
// Outcome: Accepted
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int halfSize = nums.size() / 2;
        vector<int> pos;
        vector<int> neg;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        for (int j = 0; j < halfSize; ++j){
            nums[2*j] = pos[j];
            nums[(2*j) + 1] = neg[j];

        }
        return nums;
    }
};
// Attempt 3: Two pointer approach; both pointers at beginning
// Outcome: Accepted
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 1;
        vector<int> copy(nums);
        for (int i = 0; i < nums.size(); ++i){
            if (copy[i] > 0 && pos < nums.size()){
                nums[pos] = copy[i];
                pos += 2;
            }
            else if (copy[i] < 0 && neg < nums.size()){
                nums[neg] = copy[i];
                neg += 2;
            }
        }
        return nums;
    }
};
