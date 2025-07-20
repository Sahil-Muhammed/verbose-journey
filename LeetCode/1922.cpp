// https://leetcode.com/problems/count-good-numbers/description/
// Attempt 1: Using binary exponentiation to raise powers of five and four
// Outcome: Accepted
class Solution {
public:
    long long binExp(long long a, long long b){
        if (b == 0){
            return 1;
        }

        if ((b&1) == 0){
            return binExp(a*a % 1000000007, b >> 1) % 1000000007;
        }
        return a * binExp(a*a % 1000000007, (b >> 1)) % 1000000007;
    }
    int countGoodNumbers(long long n) {
        long long countFour = n/2;
        long long countFive = n - countFour;
        long long ans = (binExp(5, countFive) % (1000000007)) * 1LL * (binExp(4, countFour) % (1000000007)) % 1000000007;
        return (int)ans;
    }
};
