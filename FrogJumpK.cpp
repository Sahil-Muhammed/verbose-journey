#include <bits/stdc++.h>
int recursion(int pos, int k, std::vector<int> arr){
	if (pos == 0){
		return 0;
	}
	int cost = 0, minCost = INT_MAX;
	for (int i = 1; i <= k; ++i){
		if (pos - i >= 0){
			cost = recursion(pos - i, k, arr) + std::abs(arr[pos] - arr[pos-i]);
			minCost = std::min(cost, minCost);
		}
	}
	return minCost;
}
int memo(int pos, int k, std::vector<int> arr, std::vector<int>& dp){
	if (pos == 0){
		return 0;
	}
	if (dp[pos] != -1){
		return dp[pos];
	}
	int cost = 0, minCost = INT_MAX;
	for (int i = 1; i <= k; ++i){
		if (pos - i >= 0){
			cost = memo(pos - i, k, arr, dp) + std::abs(arr[pos] - arr[pos - i]);				minCost = std::min(minCost, cost);	
		}	
	}
	return dp[pos] = minCost;
}
int tabulation(int k, std::vector<int> arr, std::vector<int>& dp){
	dp[0] = 0;
	for (int i = 1; i < arr.size(); ++i){
		int path1 = INT_MAX;
		for (int j = 1; j <= k; ++j){
			if (i - j >= 0){
				path1 = std::min(path1, dp[i-j] + std::abs(arr[i] - arr[i-j]));	
			} 
		}
		dp[i] = path1;
	}
	return dp[arr.size() - 1];
}
int main(){
	int n, k, num;
	std::cin >> n >> k;
	std::vector<int> arr;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	std::vector<int> dp(arr.size(), -1);
	int ans = tabulation(k, arr, dp);
	std::cout << ans << std::endl;
	return 0;
}
