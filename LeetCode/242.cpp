// https://leetcode.com/problems/valid-anagram/
// Attempt 1: Store count and compare
// Outcome: Accepted
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<int> arrs (26, 0);
        vector<int> arrt (26, 0);
        for (int i = 0; i < s.size(); ++i){
            arrs[(s[i] - 'a')]++;
            arrt[(t[i] - 'a')]++;
        }
        return arrs == arrt;
    }
};
