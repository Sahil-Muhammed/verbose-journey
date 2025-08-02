#include <bits/stdc++.h>
#include <chrono>
long long gcd(long long a, long long b){
	if (b > a){
		return gcd(b, a);
	}
	if (b == 0){
		return a;
	}
	return gcd(b, a%b);
}
int main(){
	long long a, b;
	std::cin >> a >> b;
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << gcd(a, b) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Time taken: " << time.count() << std::endl;
	return 0;
}
