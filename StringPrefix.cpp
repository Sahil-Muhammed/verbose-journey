#include <bits/stdc++.h>
std::string longestPrefix(std::vector<std::string> arr){
	sort(arr.begin(), arr.end());
	std::unordered_set<std::string> st;
	for (int i = 0; i < arr.size(); ++i){
		st.insert(arr[i]);
	}
	for (int i = arr.size() - 1; i >= 0; --i){
		if (i > 0){
			if (arr[i].size() == arr[i-1].size()){
				continue;
			}
		}
		int j = 1;
		for (j = 1; j < arr[i].size(); ++j){
			if (st.find(arr[i].substr(0, arr[i].size() - j)) != st.end()){
				continue;
			}
			else{
				break;
			}
		}
		if (j == arr[i].size()){
			return arr[i];
		}
	}
	std::string temp = "";
	return temp; 
}
int main(){
	int n;
	std::cin >> n;
	std::vector<std::string> arr;
	for (int i = 0; i < n; ++i){
		std::string temp;
		std::cin >> temp;
		arr.push_back(temp);
	}
	std::string ans = longestPrefix(arr);
	std::cout << ans << std::endl;
	return 0;
}
