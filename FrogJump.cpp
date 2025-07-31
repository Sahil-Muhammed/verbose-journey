#include <bits/stdc++.h>
int minCostFrogJump(int pos, std::vector<int> arr, std::vector<int>& dp){
	if (pos <= 0){
		return 0;
	}
	if (dp[pos] != -1){
		return dp[pos];
	}
	int left = minCostFrogJump(pos-1, arr, dp) + abs(arr[pos] - arr[pos - 1]);
	int right = INT_MAX;
	if (pos > 1){
		right = minCostFrogJump(pos - 2, arr, dp) + abs(arr[pos] - arr[pos - 2]);
	}
	return dp[pos] = std::min(left, right);
}
int minCost(vector<int>& height) {
        int prev2 = 0, prev1;
        if (height.size() == 1){
            return 0;
        }
        prev1 = abs(height[1] - height[0]);
        int curr = 0;
        for (int i = 2; i < height.size(); ++i){
            curr = min(prev1 + abs(height[i] - height[i-1]), prev2 + abs(height[i] - height[i-2]));
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
int main(){
	int n, num = 0;
	std::cin >> n;
	std::vector<int> arr;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	std::vector<int> dp(n+1, -1);
	int ans = minCostFrogJump(n-1, arr, dp);
	std::cout << ans << std::endl;
	return 0;
}
