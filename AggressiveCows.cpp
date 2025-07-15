#include <bits/stdc++.h>
bool possible(std::vector<int> arr, int cows, int minDist){
    int j = 1, prev = arr[0], curr = 0;
    cows--;
    while (cows && j < arr.size()){
        curr = arr[j];
        if ((curr - prev) >= minDist){
            //std::cout << "\t" << prev << " " << curr << " j = " << j << std::endl;
            cows--;
            prev = curr;
        }
        j++;
    }
    //std::cout << "\t\t" << cows << " j = " << j << std::endl;
    if (cows != 0){
        return false;
    }
    return true;
}
int maxDist(std::vector<int> arr, int cows){
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[arr.size() - 1] - arr[0];
    while (low <= high){
        int mid = low + (high - low)/2;
        bool val = possible(arr, cows, mid);
        std::cout << mid << " " << val << std::endl;
        if (val == true){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}
int main() {
    int n, num = 0, cows = 0;
    std::cin >> n >> cows;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    int ans = maxDist(arr, cows);
    std::cout << ans << std::endl;
    return 0;
}