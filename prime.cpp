#include <bits/stdc++.h>
bool isPrime(int n){
	if (n < 2){
		return false;
	}
	if (n == 2){
		return true;
	}
	for (int i = 2; i*i <= n; ++i){
		if (n%i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	std::cin >> n;
	std::cout << isPrime(n) << std::endl;
	return 0;
}
