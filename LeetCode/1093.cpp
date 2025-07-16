// https://leetcode.com/problems/largest-odd-number-in-string/
// Attempt 1: Using two pointers from the end until an odd number is reached
// Outcome: Accepted
class Solution {
public:
    string largestOddNumber(string num) {
        int left = num.size() - 1, right = num.size() - 1;
        while (left >= 0 && (num[left] - '0')%2 == 0){
            left--;
        }
        right = left;
        left = 0;
        num = num.substr(0, right+1);
        return num;
    }
};
