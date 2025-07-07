#include <bits/stdc++.h>
double pow(double a, int b){
    if (b == 0){
        return 1;
    }
    else if (b < 0){
        return 1 / pow(a, -1*b);
    }
    else if (b & 1 == 1){
        return a * pow(a * a, (b-1)/2);
    }
    else{
        return pow(a * a, b/2);
    }
    return -1;
}
int main(){
    double n;
    int a;
    std::cin >> n >> a;
    double ans = pow(n, a);
    std::cout << ans << std::endl;
    return 0;
}
