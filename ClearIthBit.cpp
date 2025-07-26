#include <bits/stdc++.h>
int main(){
    int n, i;
    std::cin >> n >> i;
    int max = INT_MAX;
    max = max ^ (1 << i);
    n = n & max;
    std::cout << n << std::endl;
    return 0;
}
