#include <bits/stdc++.h>
int main(){
    int a, b;
    std::cin >> a >> b;
    a = INT_MAX;
    b = INT_MIN;
    std::cout << a << " " << b << std::endl;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    std::cout << "a = " << a << " b = " << b << std::endl;
    return 0;
}
