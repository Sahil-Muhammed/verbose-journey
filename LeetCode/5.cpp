// https://leetcode.com/problems/longest-palindromic-substring/
// Attempt 1: Brute force
// Outcome: TLE; 79/142

class Solution {
public:
    bool checkPalin(string s){
        int low = 0, high = s.size() - 1;
        while (low <= high){
            if (s[low] == s[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        pair<int, int> maxPal;
        int len = 0;
        for (int i = 0; i < s.size(); ++i){
            for (int j = i; j < s.size(); ++j){
                string puthan = s.substr(i, j-i+1);
                bool val = checkPalin(puthan);
                if (val == true){
                    len = j-i+1;
                    if (len > (maxPal.second - maxPal.first)){
                        maxPal.first = i;
                        maxPal.second = j;
                    }
                }
            }
        }
        string longestPalin = s.substr(maxPal.first, (maxPal.second - maxPal.first + 1));
        return longestPalin;
    }
};
// Attempt 2: Check every possible substring in every iteration by starting from centre and expanding to left and right to get maximum length palindromic substring
// Outcome: Accepted
class Solution {
public:
    string centrePalin(int left, int right, string s){
        while (left >= 0 &&  right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string maxStr = s.substr(0, 1);
        for (int i = 0; i < s.size(); ++i){
            string even = centrePalin(i, i+1, s);
            string odd = centrePalin(i, i, s);
            if (even.size() > maxStr.size()){
                maxStr = even;
            }
            if (odd.size() > maxStr.size()){
                maxStr = odd;
            }
        }
        return maxStr;
    }
};
