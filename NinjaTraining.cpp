#include <bits/stdc++.h>
#include <chrono>
int max3(int a, int b, int c){
	if (a > b){
		if (a > c){
			return a;
		}
		return c;
	}
	if (b > c){
		return b;
	}
	return c;
}
int recursion(int pos, int currChoice, std::vector<std::vector<int>> points){
// 	if (pos < 0){
// 		return 0;
// 	}

//     if (dp[pos][currChoice] != -1){
//         return dp[pos][currChoice];
//     }
// 	if (pos == 0){
// 		int maximum = 0;
// 		for (int i = 0; i < 3; ++i){
// 			if (i == currChoice){
// 				continue;
// 			}
// 			maximum = std::max(maximum, points[pos][i]);
// 		}
// 		return dp[0][currChoice] = maximum;
// 	}
// 	int maxi = 0;
    
// 	for (int i = 0; i < 3; ++i){
// 		if (i == currChoice){
// 			continue;
// 		}
// 		maxi = std::max(points[pos][i] + recursion(pos - 1, i, points, dp), maxi);
// 	}
// 	return dp[pos][currChoice] = maxi;
//     return maxi;
    std::vector<std::vector<int>> dp(points.size() + 1, std::vector<int> (4, -1));
    
    int prev0 = max3(points[0][0], points[0][1], points[0][2]);
    int prev1 = prev0;
    int prev2 = prev1;
	std::vector<int> prev;
	prev.push_back(prev0);
	prev.push_back(prev1);
	prev.push_back(prev2);
    int maxi = 0;
    for(int i = 1; i < points.size(); ++i){
        for (int j = 0; j < 3; ++j){
            maxi = std::max(maxi, points[i][j] + prev[j]);
        }
	
    }
}
int main(){
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> points;
	
	for (int i = 0; i < n; ++i){
		int temp1 = 0, temp2 = 0, temp3 = 0;
		std::vector<int> temp;
		std::cin >> temp1 >> temp2 >> temp3;
		temp.push_back(temp1);
		temp.push_back(temp2);
		temp.push_back(temp3);
		points.push_back(temp);
	}
	
	std::vector<std::vector<int>> dp(n+1, std::vector<int>(4, -1));
	
	auto begin = std::chrono::high_resolution_clock::now();
	int ans = recursion(n - 1, n, points, dp);
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
	
	std::cout << "Time taken: " << time.count() << std::endl;
	std::cout << ans << std::endl;
	return 0;
}
