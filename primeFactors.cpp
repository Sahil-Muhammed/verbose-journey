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
	/*for (int i = 2; i <= n; ++i){
		if (n%i == 0){
			if (isPrime(i) == true){
				std::cout << i << " ";
			}
		}
	}*/
	for (int i = 2; i <= n; ++i){
		if (n%i == 0){
			std::cout << i << " ";
			while (n % i == 0){
				n = n/i;
			}
		}
			
	}
	std::cout << std::endl;
	return 0;
}
