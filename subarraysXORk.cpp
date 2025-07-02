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
int subarrayXOR1(std::vector<int> arr, int k){
    std::unordered_map<int, int> hashmap;
    int yexor = 0, count = 0;
    hashmap[0] = 1;
    for (int i = 0; i < arr.size(); ++i){
        yexor = yexor ^ arr[i];
        count += hashmap[yexor ^ k];
        hashmap[yexor] += 1;
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
    int ans = subarrayXOR1(arr, k);
    std::cout << ans << std::endl;
    return 0;
}
