#include <bits/stdc++.h>
int main(){
    int n, i;
    std::cin >> n >> i;
    // one way to check if the ith bit is set or not
    /*if ((n & (1 << i)) > 0){
        std::cout << "The " << i << "th bit is set.\n";
    }
    else{
        std::cout << "The " << i << "th bit is not set\n";
        }*/
    // second way
    if ((n >> i) & 1 > 0){
        std::cout << "The " << i << "th bit is set.\n";
    }
    else{
        std::cout << "THe " << i << "th bit is not set.\n";
    }
    return 0;
}
