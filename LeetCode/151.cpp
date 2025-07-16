// https://leetcode.com/problems/reverse-words-in-a-string/description/
// Attempt 1: Two pointer approach iterating from end
// Outcome: Accepted
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        s = s.substr(i, s.size() - i + 1);

        string res;
        int left = s.size() - 1, right = s.size() - 1;
        while (left > -1 && s[left] == ' '){
            left--;
        }
        right = left;
        while (left > -1){
            if (s[left] == ' '){
                for (int j = left+1; j <= right; ++j){
                    res += s[j];
                }
                while (left >= 0 && s[left] == ' '){
                    left--;
                }
                right = left;
                res += ' ';
            }
            else{
                left--;
            }
        }
        for (int j = left+1; j <= right; ++j){
                    res += s[j];
        }
        return res;
    }
};
