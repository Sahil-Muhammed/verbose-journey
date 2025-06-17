#include <bits/stdc++.h>
//Euclidean Algorithm
int gcd(int a, int b){
    if (a%b == 0){
        std::cout << "Reached end!\n";
        return b;
    }
    std::cout << "Hi!\n";
    return gcd(b, a%b);
}

int main(){
    int a, b;
    std::cin >> a >> b;
    int result = gcd(a, b);
    std::cout << "GCD of " << a << " and " << b << " is " << result << std::endl;
    return 0;
}

// Extended Euclidean Algorithm (pending)
