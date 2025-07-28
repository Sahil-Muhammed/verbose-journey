#include <bits/stdc++.h>
std::vector<int> findSingle(std::vector<int> arr){
	std::vector<int> ans;
	std::unordered_map<int, int> freq;
	for (int i = 0; i < arr.size(); ++i){
		freq[arr[i]]++;
	}
	for (int i = 0; i < arr.size(); ++i){
		if (freq[arr[i]] == 1){
			ans.push_back(arr[i]);
		}
	}
	return ans;
}
std::vector<int> findSingleBitManip(std::vector<int> arr){
	int val = 0;
	for (int i = 0; i < arr.size(); ++i){
		val = val ^ arr[i];
	}
	val = (val & (val - 1)) ^ val; // gives the rightmost set bit in the xor of all numbers in the array
	int b1 = 0, b2 = 0;
	for (int i = 0; i < arr.size(); ++i){
		if ((arr[i] & val) > 0){
			b1 = b1 ^ arr[i];
		}
		else{
			b2 = b2 ^ arr[i];
		}
	}
	return {b1, b2};
}
int main(){
	std::vector<int> arr;
	int num = 0, n = -1;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	std::vector<int> ans;
	ans = findSingleBitManip(arr);
	for (int i = 0; i < ans.size(); ++i){
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
