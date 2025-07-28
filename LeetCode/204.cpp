// https://leetcode.com/problems/count-primes/description/
// Attempt 1: Using Sieve of Eratosthenes
// Outcome: Accepted
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> arr;
        arr.push_back(1);
        for (int i = 1; i <= n; ++i){
            arr.push_back(1);
        }
        for (int i = 2; i*i <= n; ++i){
            if (arr[i] == 1){
                count++;
                for (int j = i*i; j <= n; j+=i){
                    arr[j] = 0;
                }
            }
        }
        int sum = 0;
        for (int i = 2; i < n; ++i){
            sum += arr[i];
        }
        return sum;
    }
};
