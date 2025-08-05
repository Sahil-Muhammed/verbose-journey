#include <bits/stdc++.h>
int maxLen(std::vector<int> arr, int target){
	int maxL = 0, sum = 0;
	std::unordered_map<int, int> hashmap;
	for (int i = 0; i < arr.size(); ++i){
		sum += arr[i];
		if (hashmap.find(sum - target) != hashmap.end()){
			maxL = std::max(maxL, i - hashmap[sum - target]);
		}
		if (sum == target){
			maxL = std::max(maxL, i+1);
		}
		if (hashmap.find(sum - target) == hashmap.end()){
			hashmap[sum] = i;
		}
	}
	return maxL;
}
int main(){
	int n, num, target;
	std::vector<int> arr;
	std::cin >> n >> target;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	int ans = maxLen(arr, target);
	std::cout << ans << std::endl;
	return 0;
}
