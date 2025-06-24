// https://leetcode.com/problems/move-zeroes/
// Move Zeroes
// Attempt 1: Swap all zero elements with non-zero elements only when zero element comes first.
// Outcome: Accepted
class Solution {
public:
    void swap(int* a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[j] == 0){
                if (nums[j] != nums[i]){
                    swap(&nums[i], &nums[j++]);
                }
            }
            else{
                j++;
            }
        }
    }
};

// ChatGPT Approach: Two pointer approach where we move one pointer every time we see non-zero element and the other pointer to iterate through the array
// Outcome: Accepted
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }

        // Fill the rest with zeros
        for (int i = lastNonZeroIndex; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

// Attempt 3 (most solutions given): Use two-pointer approach; move non-zero elements to the front
// Outcome: Accepted
class Solution {
public:
    void swap(int* a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != 0){
                swap(&nums[i], &nums[j++]);
            }
        }
    }
};
