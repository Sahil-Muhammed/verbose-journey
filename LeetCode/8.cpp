// https://leetcode.com/problems/string-to-integer-atoi/description/
// Attempt 1: Remove whitespace, check for sign, convert to number, be wary of overflow
// Outcome: Accepted
class Solution {
public:
    int myAtoi(string s) {
        long num = 0;
        int i = 0;
        while (i < s.size() && s[i] == ' '){
            i++;
        }

        if (i == s.size()){
            return 0;
        }
        int minus = 1;
        if (s[i] == '-'){
            minus = -1;
            i++;
        }
        else if (s[i] == '+'){
            minus = 1;
            i++;
        }
        while (i < s.size() && s[i] >= '0' && s[i] <= '9'){
            if (minus == -1 && num*10 + (s[i] - '0') >= (long long)INT_MAX+1){
                return INT_MIN;
            }
            else if (num*10 + (s[i] - '0') >= INT_MAX && minus == 1){
                return INT_MAX;
            }
            num *= 10;
            num += s[i] - '0';
            i++;
        }
        return (int)num*minus;
    }
};
