// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// Attempt 1: Track max value of opening brackets - closing brackets at any time in iteration
// Outcome: Accepted
class Solution {
public:
    int maxDepth(string s) {
        int max = 0, co = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                co++;
                if (max < co){
                    max = co;
                }
            }
            else if (s[i] == ')'){
                co--;
            }
            else{
                continue;
            }
        }
        return max;
    }
};
