#include <bits/stdc++.h>
int main(){
	int n;
	std::cin >> n;
	n = n & (n-1);
	std::cout << n << std::endl;
	return 0;
}
