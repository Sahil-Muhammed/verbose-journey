#include <bits/stdc++.h>
int fib(int a){
    if (a == 0 || a == 1){
        return a;
    }
    return fib(a-1) + fib(a-2);
}
int main(){
    int n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;

}
