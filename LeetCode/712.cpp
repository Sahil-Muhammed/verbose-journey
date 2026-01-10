// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2026-01-10
// Attempt 1: Finding LCS + Backtrack to get string
// Outcome: Didn't pass testcases
class Solution {
    // int f(vector<vector<int>>& dp, string& s1, string& s2, int i, int j){
    //     if (i >= s1.size() || j >= s2.size()) return 0;
    //     if (dp[i][j] != -1) return dp[i][j];

    //     if (s1[i] == s2[j]){
    //         dp[i][j] = 1+f(dp, s1, s2, i+1, j+1);
    //     }
    //     else dp[i][j] = max(f(dp, s1, s2, i+1, j), f(dp, s1, s2, i, j+1));
    //     return dp[i][j];
    // }

    void freq(string& s, unordered_map<char, int>& mp){
        for (auto c:s) mp[c]++;
    }

    int del(unordered_map<char, int>& bigMap, unordered_map<char, int>& smallMap){
        int sum = 0;
        for (auto [c, count]:bigMap){
            int times = count - smallMap[c];
            sum += c*times;
        }
        return sum;
    }

    void printDP(vector<vector<int>>& dp){
        for (int i = 0; i < dp.size(); ++i){
            for (int j = 0; j < dp[i].size(); ++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        string s = "";

        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, -1));
        for (int j = 0; j<=n2; j++) dp[0][j] = 0;
        for (int i = 0; i<=n1; i++) dp[i][0] = 0;
        for (int i = 1; i<=n1; i++){
            for (int j = 1; j<=n2; j++){
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int lcs = dp[n1][n2];
        int i;
        while(lcs > 0){

        }

        cout << lcs;
        cout << s;

        unordered_map<char, int> map_s, map_s1, map_s2;
        freq(s, map_s);
        freq(s1, map_s1);
        freq(s2, map_s2);

        int sum = del(map_s1, map_s) + del(map_s2, map_s);
        return sum;
    }
};
