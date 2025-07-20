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
// Attempt 2: Using recursion
// Outcome: Accepted
class Solution {
public:
    int recursiveAtoi(string s, int len, int* sign, int* num, int reading){
        if (len == 0){
            return (*num)*(*sign);
        }

        if (s[0] == ' '){
            if (reading == 1){
                return (*num)*(*sign);
            }
            *num = recursiveAtoi(s.substr(1, len-1), len-1, sign, num, reading);
        }

        else if (s[0] == '-'){
            if (reading == 1){
                return (*num)*(*sign);
            }
            *sign = -1;
            reading = 1;
            *num = recursiveAtoi(s.substr(1, len-1), len-1, sign, num, reading);
        }

        else if (s[0] == '+'){
            if (reading == 1){
                return (*num)*(*sign);
            }
            *sign = 1;
            reading = 1;
            *num = recursiveAtoi(s.substr(1, len-1), len-1, sign, num, reading);
        }

        else if (s[0] >= '0' && s[0] <= '9'){
            reading = 1;
            if (*sign == 1 && ((long)(*num)*10 + (s[0] - '0')) >= INT_MAX){
                return INT_MAX;
            }
            else if (*sign == -1 && ((long)(*num)*10 + (s[0] - '0')) > INT_MAX){
                return INT_MIN;
            }
            *num = (*num)*10 + (s[0] - '0');
            *num = recursiveAtoi(s.substr(1, len-1), len-1, sign, num, reading);
            //cout << *num << " sign is " << *sign << endl;

        }

        else{
            return (*num)*(*sign);
        }

        return *num;
    }
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int reading = 0;
        return recursiveAtoi(s, s.size(), &sign, &num, reading);
        return num;
    }
};
