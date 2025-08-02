// https://leetcode.com/problems/palindromic-substrings/description/
// Attempt 1: Using two pointer
// Outcome: Accepted
class Solution {
public:
    int isPalin(int left, int right, string s){
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        for (int i = 0; i < s.size(); ++i){
            ans += isPalin(i, i, s); // odd-length
            if (i < s.size() - 1){
                ans += isPalin(i, i+1, s); // even-length
            }
        }
        return ans;
    }
};
