// https://leetcode.com/problems/rotate-string/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    string rotate(string s){
        char temp = s[0];
        for (int i = 0; i < s.size() - 1; ++i){
            s[i] = s[i+1];
        }
        s[s.size() - 1] = temp;
        return s;
    }
    bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); ++i){
            if (s == goal){
                return true;
            }
            s = rotate(s);
        }
        return false;
    }
};
// Attempt 2: Using find and making a string which has all rotations of goal
// Outcome: Accepted
class Solution {
public:
    string rotate(string s){
        char temp = s[0];
        for (int i = 0; i < s.size() - 1; ++i){
            s[i] = s[i+1];
        }
        s[s.size() - 1] = temp;
        return s;
    }
    // abcdeabcd
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()){
            return false;
        }
        s += s;
        if (s.find(goal) != string::npos){
            return true;
        }
        return false;

    }
};
