// https://leetcode.com/problems/powx-n/description/
// Attempt 1: Using binary exponentiation
// Outcome: Accepted
class Solution {
public:
    double power(double x, int n){
        if (n == 0 || x == 1.0 || (x == -1 && n%2 == 0)){
            return 1;
        }
        if (n == INT_MIN){
            return 0.0;
        }

        if (n > 0){
            if ((n&1) == 1){
                return x * power(x*x, (n-1)/2);
            }
            return power(x*x, n/2);
        }

        return 1 / power(x, -1*n);
    }
    double myPow(double x, int n) {
        return power(x, n);
    }
};
