#include <bits/stdc++.h>
std::vector<int> ExtEuclid(long long a, long long b){
	if (a < b){ return ExtEuclid(b, a);}
	if (b == 0){
		return {a, 1, 0};
	}
	long long q = a / b;
	long long r = a%b;
	std::vector<int> temp = ExtEuclid(b, r);
	return {temp[0], temp[2], temp[1] - (q*temp[2])};
}
int main(){
	long long a, b;
	std::cin >> a >> b;
	std::vector<int> ans = ExtEuclid(a, b);
	std::cout << "ax + by = d" << std::endl;
	std::cout << a << "*" << ans[1] << " + " << b << "*" << ans[2] << " = " << ans[0] << std::endl;	
	return 0;
}
