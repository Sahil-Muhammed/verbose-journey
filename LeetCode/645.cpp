// https://leetcode.com/problems/set-mismatch/
// Attempt 1: Using a hashmap
// Outcome: Accepted
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i){
        hash[nums[i]] += 1;
    }
    int mis = -1, rep = -1;
    for (int i = 1; i <= nums.size(); ++i){
        if (hash[i] == 0){
            mis = i;
        }
        else if (hash[i] == 2){
            rep = i;
        }
        if (mis != -1 && rep != -1){
            break;
        }
    }
    vector<int> ans = {rep, mis};
    return ans;
    }
};
// Attempt 2: Use sum of first n natural numbers and sum of squares of first n natural numbers
// Outcome: Accepted
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int x = -1, y = -1;
        int n = nums.size();
        int sum = (n) * (n + 1) / 2;
        long long arrSum = 0, arrSquareSum = 0;
        for (int i = 0; i < n; ++i){
            arrSum += nums[i];
            arrSquareSum += (nums[i] * nums[i]);
        }
        long long xMinusY  = arrSum - sum;
        long long xPlusY = (n * (n+1));
        xPlusY = xPlusY * (2 * n + 1) / 6;
        xPlusY = (arrSquareSum - xPlusY) / xMinusY;
        x = (xMinusY + xPlusY) / 2;
        y = x - xMinusY;
        return {x, y};
    }
};
