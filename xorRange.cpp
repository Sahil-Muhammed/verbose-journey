#include <bits/stdc++.h>
int xorRange(int n){
	if (n%4 == 1){
                return 1;
        }
        else if (n%4 == 2){
                return n+1;
        }
        else if (n%4 == 3){
                 return 0;
        }
        return n;
}
int main(){
	int l, r;
	std::cin >> l >> r;
	int val = 0;
	/*for (int i = 1; i <= n; ++i){
		val = val ^ i;
	}
	std::cout << val << std::endl;*/
	int val1 = xorRange(l-1);
	int val2 = xorRange(r);
	val2 = val2 ^ val1;
	std::cout << val2 << std::endl;
	return 0;
}
