#include <bits/stdc++.h>
void printAllFactors(int n){
	// brute force
	for (int i = 1; i <= n; ++i){
		if (n%i == 0){
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}
void printAllFactorsBetter(int n){
	for (int i = 1; i*i <= n; ++i){
		if (n%i == 0){
			std::cout << i << " ";
			if (n/i != i){
				std::cout << n/i << " ";
			}	
		}
	}
	std::cout << std::endl;
}
int main(){
	int n;
	std::cin >> n;
	printAllFactorsBetter(n);
	return 0;
}
