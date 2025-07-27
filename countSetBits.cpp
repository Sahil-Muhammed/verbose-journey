#include <bits/stdc++.h>
int main(){
	int n;
	std::cin >> n;
	//int count = __builtin_popcount(n); //this is a built-in function in c++
	int count = 0;
	// brute force
	/*while (n > 0){
		count += n&1;
		n = n >> 1;
	}*/
	// optimal
	while (n > 0){
		count++;
		n = n & (n-1);
	}
	std::cout << count << std::endl;
	return 0;
}	
