#include <bits/stdc++.h>
int sumIndex(int a, int b, std::vector<int> arr){
    int sum = 0;
    for (int i = a; i <= b; ++i){
        sum += arr[i];
    }
    return sum;
}
void Print(std::vector<std::pair<int, int>> arr){
    for (auto it : arr){
        std::cout << it.first << " " << it.second << std::endl;
    }
}
void generateSubarray(std::vector<int> nums, int k){
    std::vector<std::pair<int, int>> storePairs;
    int left = 0;
    for (int right = 0; left < nums.size(); ++right){
        std::cout << left << " " << right << " ." << std::endl;
        if (right == nums.size() - 1){
            left++;
            right = left - 1;
        }
        if (sumIndex(left, right, nums) == k){
            storePairs.emplace_back(left, right);
            left++;
            right = left-1;
        }
    }
    Print(storePairs);
}
int main(){
    int n, k, num = 0;
    std::vector<int> arr;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    generateSubarray(arr, k);
    return 0;
}
