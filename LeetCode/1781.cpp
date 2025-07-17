// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    int beauty(string s){
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); ++i){
            freq[s[i] - 'a'] += 1;
        }
        int max = 0, min = INT_MAX;
        for (int i = 0; i < 26; ++i){
            if (freq[i] > max){
                max = freq[i];
            }
            if (freq[i] > 0 && freq[i] < min){
                min = freq[i];
            }
        }
        return max - min;
    }
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); ++i){
            for (int j = i; j < s.size(); ++j){
                sum += beauty(s.substr(i, j-i+1));
            }
        }
        return sum;
    }
};
