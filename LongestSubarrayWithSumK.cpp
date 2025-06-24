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
int LongestSubarray(std::vector<std::pair<int, int>> arr){
    int maxLen = 0;
    for (auto it : arr){
        if (maxLen < it.second - it.first + 1){
            maxLen = it.second - it.first + 1;
        }
    }
    return maxLen;
}
void generateSubarray(std::vector<int> nums, int k){
    std::vector<std::pair<int, int>> storePairs;
    int left = 0;
    for (int right = 0; left < nums.size(); ++right){
        int sum = sumIndex(left, right, nums);
        if (right == nums.size() - 1){
            if (left == nums.size() - 1){
                if (sum == k){
                    storePairs.emplace_back(left, right);
                }
                break;
            }
            left++;
            right = left - 1;
        }
        if (sum == k){
            storePairs.emplace_back(left, right);
            left++;
            right = left-1;
        }
        else if (sum > k){
            left++;
            right--;
        }
    }
    Print(storePairs);
    int ans = LongestSubarray(storePairs);
    std::cout << ans << std::endl;
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
