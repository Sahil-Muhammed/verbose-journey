// https://leetcode.com/problems/divide-two-integers/description/
// Attempt 1: Using leftshift bitwise operations
// Outcome: Accepted
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor){
            return 1;
        }
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1){
            return INT_MIN;
        }
        bool pos = true;
        if (dividend < 0 && divisor > 0){
            pos = false;
        }
        else if (dividend >= 0 && divisor < 0){
            pos = false;
        }
        long n = labs(dividend);
        long d = labs(divisor);
        int ans = 0;
        while (n >= d){
            int count = 0;
            while ((d << count+1) <= n){
                count++;
            }
            ans += (1 << count);
            n = n - (d << count);
        }
        if (pos == false && ans == (1 << 31)){
            return INT_MIN;
        }
        if (pos == true && ans == (1 << 31)){
            return INT_MAX;
        }
        return pos == true ? ans : -ans;
    }
};
