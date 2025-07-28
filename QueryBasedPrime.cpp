#include <bits/stdc++.h>
void findPrimeFactors(std::vector<int> arr, int num){
	while (num != 1){
		std:: cout << arr[num] << " ";
		num = num / arr[num];
	}
	std::cout << std::endl;
}
int main(){
	int n, num=0;
	std::cin >> n;
	std::vector<int> arr;
	for (int i = 0; i < n; ++i){
		std::cin >> num;
		arr.push_back(num);
	}
	
	std::vector<int> store;
	for (int i = 0; i <= 100000; ++i){;
		store.push_back(i);
	}
	for (int i = 2; i*i <= 100000; ++i){
		if (store[i] == i){
			for (int j = i*i; j <= 100000; j += i){
				if (store[j] == j){
					store[j] = i;
				}
			}
		}
	}
	
	for (int i = 0; i < n; ++i){
		findPrimeFactors(store, arr[i]);
	}
	return 0;
}
