// https://leetcode.com/problems/generate-parentheses/
// Attempt 1: Using recursion
// Outcome: Accepted
class Solution {
public:
    void recursion(vector<string>& ans, string& s, int left, int right, int n){
        if (s.size() == 2*n){
            if (left == right){
                ans.push_back(s);
            }
            return;
        }
        if (left < n){
            s.push_back('(');
            recursion(ans, s, left+1, right, n);
            s.pop_back();
        }
        if (right < left){
            s.push_back(')');
            recursion(ans, s, left, right+1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        recursion(ans, s, 0, 0, n);
        return ans;
    }
};
