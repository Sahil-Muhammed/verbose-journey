#include <bits/stdc++.h>
// every iteration only involves the remainder of previous iteration to work on
void check(int n){
    int num = 0;
    while (true){
        int bit = 0;
        std::cin >> bit;

        num = num << 1;
        num += bit;
        if (bit != 1 && bit != 0){
            break;
        }

        if (num%n == 0){
            std::cout << "Yes" << std::endl;
        }
        else{
            std::cout << "No" << std::endl;
        }
        num = num % n;
    }
}
int main(){
    int n;
    std::cin >> n;
    check(n);
    return 0;
}
