// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Attempt 1: Using recursion and storing the mapping of number and string in an array of pairs
// Outcome: Accepted
class Solution {
public:
    void recursiveTree(int pos, string digits, string ds, vector<pair<int, string>> phone, vector<string>& ans){
        if (pos == digits.size()){
            ans.push_back(ds);
            return;
        }

            for (int j = 0; j < phone[digits[pos] - '2'].second.size(); ++j){
                recursiveTree(pos+1, digits, ds+phone[digits[pos] - '2'].second[j], phone, ans);
            }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0){
            return {};
        }
        vector<pair<int, string>> phone = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> ans;
        recursiveTree(0, digits, "", phone, ans);
        return ans;
    }
};
