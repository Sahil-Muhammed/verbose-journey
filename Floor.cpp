#include <bits/stdc++.h>
int Floor(std::vector<int> arr, int low, int high, int target){
    int ans = 0;
    while (low <= high){
        int mid = (low+high)/2;
        if (arr[mid] <= target){
            ans = arr[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int n, num = 1, target = -1;
    std::cin >> n >> target;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    int ans = Floor(arr, 0, arr.size() - 1, target);
    std::cout << "Floor is: " << ans << std::endl;
    return 0;
}
