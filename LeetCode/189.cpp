// https://leetcode.com/problems/rotate-array/
// Rotate array
// Attempt 1: Rotate the elements one by one and repeat it k times.
// Outcome: 37/38 testcases passed. TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = 0;
        int size = nums.size();
        int realK = k % size;
        cout << "The size of the array is " << size << endl;
        for (int i = 0; i < realK; ++i){
            temp = nums[size - 1];
            nums.erase(nums.begin() + size - 1);
            nums.insert(nums.begin(), temp);
        }
    }
};

// Attempt 2: Reversal of arrays

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = 0;
        int size = nums.size();
        int realK = k % size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + realK);
        reverse(nums.begin() + realK, nums.end());
    }
};

// Attempt 3: Cyclic

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tempNum = -1, prevNum=-1, currentIndex = 0, nextIndex = 0, startIndex = -1, count = 0, size = nums.size();
        for (startIndex = 0; count < size; ++startIndex){
            currentIndex = startIndex;
            prevNum = nums[startIndex];
            do{
                nextIndex = (currentIndex + k) % size;
                tempNum = nums[nextIndex];
                nums[nextIndex] = prevNum;
                prevNum = tempNum;
                currentIndex = nextIndex;
                count++;
            } while (startIndex != currentIndex);
        }
    }
};
