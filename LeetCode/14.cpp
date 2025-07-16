// https://leetcode.com/problems/longest-common-prefix/description/
// Attempt 1: Iterate until the minlength of string, iterate through the entire array of strings and check if each character is same, stop and return the string when they are unequal
// Outcome: Accepted
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        int minLen = INT_MAX;
        for (int j = 0; j < strs.size(); ++j){
            if (minLen > strs[j].size()){
                minLen = strs[j].size();
            }
        }
        cout << minLen << endl;
        string res;
        int flag = 0;
        for (int i = 0; i < minLen; ++i){
            for (int k = 0; k < strs.size() - 1; ++k){
                if (strs[k][count] == strs[k+1][count]){
                    continue;
                }
                else{
                    return res;
                }
            }
            count++;
            res = strs[0].substr(0, count);
        }
        return res;
    }
};
