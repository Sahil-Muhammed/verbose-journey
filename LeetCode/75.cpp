// https://leetcode.com/problems/sort-colors/description/
// Attempt 1: Take the count of each, rewrite the array
// Outcome: Accepted
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for (auto it = nums.begin(); it != nums.end(); it += 1){
            if (*it == 0){
                count0++;
            }
            else if (*it == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        int i = 0, j = 0, k = 0;
        for (i = 0; i < count0; ++i){
            *(nums.begin() + i) = 0;
        }
        for (j = i; j < i + count1; ++j){
            *(nums.begin() + j) = 1;
        }
        for (k = j; k < nums.size(); ++k){
            *(nums.begin() + k) = 2;
        }
    }
};
// Attempt 2: Three pointer approach; use the mid pointer to traverse and swap accordingly
// Outcome: Accepted
class Solution {
public:
    void swap(int* a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = nums.size() - 1;
        for (count1 = 0; count1 <= count2; ++count1){
            if (nums[count1] == 0){
                swap(&nums[count1], &nums[count0]);
                count0++;
            }
            else if (nums[count1] == 1){
                continue;
            }
            else{
                swap(&nums[count1], &nums[count2]);
                count2--;
                count1--;
            }
        }
    }
};
