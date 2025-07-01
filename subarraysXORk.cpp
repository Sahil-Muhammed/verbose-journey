#include <bits/stdc++.h>

int subarrayXOR(std::vector<int> arr, int k){
    int count = 0;
    for (int i = 0; i < arr.size(); ++i){
        int yexWor = 0;
        for (int j = i; j < arr.size(); ++j){
            yexWor = yexWor ^ arr[j];
            if (yexWor == k){
                std::cout << i << " " << j << std::endl;
                count++;
            }
        }
    }
    return count;
}
int main(){
    int n, num, k;
    std::cin >> n >> k;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    int ans = subarrayXOR(arr, k);
    std::cout << ans << std::endl;
    return 0;
}
