// https://leetcode.com/problems/isomorphic-strings/description/
// Attempt 1: Using a hashmap and doing the same process in reverse
// Outcome: Accepted
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashmap, hashmap1;
        int size = s.size();
        for (int i = 0; i < size; ++i){
            if (hashmap.find(s[i]) == hashmap.end()){
                hashmap[s[i]] = t[i];
            }
            else{
                if (hashmap[s[i]] != t[i]){
                    return false;
                }
            }
        }
        for (int i = 0; i < size; ++i){
            if (hashmap1.find(t[i]) == hashmap1.end()){
                hashmap1[t[i]] = s[i];
            }
            else{
                if (hashmap1[t[i]] != s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
