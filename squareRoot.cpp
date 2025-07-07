#include <bits/stdc++.h>
int sqRtBinSearch(int target){
    int low = 1, high = target;
    while (low <= high){
        int mid = (low+high)/2;
        if (mid * mid > target){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return high;
}
int main(){
    int target = 0;
    std::cin >> target;
    int ans = sqRtBinSearch(target);
    std::cout << ans << std::endl;
    return 0;
}
