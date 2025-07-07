#include <bits/stdc++.h>
long long pow(int a, int b, int target){
    if (a > target){
        return target+1;
    }
    if (b == 0){
        return 1;
    }
    else if (b < 0){
        return 1 / pow(a, -1*b, target);
    }
    else if (b & 1 == 1){
        return a * pow(a * a, (b-1)/2, target);
    }
    else{
        return pow(a * a, b/2, target);
    }
    return -1;
}
long long binSearch(long long target, int n){
    long long low = 1, high = target;
    while (low <= high){
        int mid = (low + high)/2;
        if (pow(mid, n, target) > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return high;
}
int main(){
    long long target, n = 0;
    std::cin >> target >> n;
    long long ans = binSearch(target, n);
    std::cout << ans << std::endl;
    return 0;
}
