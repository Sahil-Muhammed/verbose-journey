#include <bits/stdc++.h>
int main(){
	int n;
	std::cin >> n;
	bool val = n > 0 && !(n & (n-1));
	if (val == true){
		std::cout << n << " is a power of 2\n";
	}
	else{
		std::cout << n << " is not a power of 2\n";
	}
	return 0;
}
