// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Attempt 1: Brute force
// Outcome: 201/212; TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0, maxProf = 0;
        for (int i = 0; i < prices.size() - 1; ++i){
            buy = i;
            for (int j = i + 1; j < prices.size(); ++j){
                sell = j;
                int yield = prices[sell] - prices[buy];
                if (yield > 0 && yield > maxProf){
                    maxProf = yield;
                }
            }
        }
        return maxProf;
    }
};
// Attempt 2: Subtract current iteration element from min
// Outcome: Accepted
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], maxProf = 0;
        for (int i = 0; i < prices.size(); ++i){
            if (prices[i] - buy > maxProf){
                maxProf = prices[i] - buy;
            }
            if (prices[i] < buy){
                buy = prices[i];
            }
        }
        return maxProf;
    }
};
