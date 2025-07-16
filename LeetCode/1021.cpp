// https://leetcode.com/problems/remove-outermost-parentheses/description/
// Attempt 1: Using two variables to keep track of opening and closing brackets, then appending to result only when co > cc
// Outcome: Accepted
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int co = 0, cc = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                if (co > cc){
                    res += s[i];
                }
                co++;
            }
            else{
                cc++;
                if (co > cc){
                    res += s[i];
                }
            }
        }
        return res;
    }
};
