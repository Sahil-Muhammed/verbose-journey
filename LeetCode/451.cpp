// https://leetcode.com/problems/sort-characters-by-frequency/description/
// Attempt 1: Using 2 maps (one for storing frequency and other for reverse storage)
// Outcome: Accepted
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charFreq;
        for (int i = 0; i < s.size(); ++i){
            charFreq[s[i]]++;
        }
        map<int, string> freqChar;
        for (auto it : charFreq){
            freqChar[it.second] += string(it.second, it.first);
        }

        string res;
        for (auto it = freqChar.rbegin(); it != freqChar.rend(); it++){
            res += (*it).second;
        }
        return res;
    }
};
