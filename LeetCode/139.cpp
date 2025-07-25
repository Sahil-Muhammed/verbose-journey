// https://leetcode.com/problems/word-break/description/
// Attempt 1: Using backtracking
// Outcome: TLE; 33/47
class Solution {
public:
    void backtrack(string s, vector<string> wordDict, bool& ans){
        //cout << s << endl;
        if (s.size() == 0){
            ans = true;
            return;
        }
        for (int i = 0; i < wordDict.size(); ++i){
            if (s.size() >= wordDict[i].size()){
                if (s.compare(0, wordDict[i].size(), wordDict[i]) == 0){
                    if (s.size() == wordDict[i].size()){
                        ans = true;
                        return;
                    }
                    backtrack(s.substr(wordDict[i].size(), s.size() - wordDict[i].size()), wordDict, ans);
                }
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = false;
        backtrack(s, wordDict, ans);
        return ans;
    }
};
