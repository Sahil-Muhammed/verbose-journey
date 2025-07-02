#include <bits/stdc++.h>
int countInversions1(std::vector<int> nums){
    int count = 0;
    for (int i = 0; i < nums.size(); ++i){
        for (int j = i + 1; j < nums.size(); ++j){
            if (nums[i] > nums[j]){
                count++;
            }
        }
    }
    return count;
}
// Time Complexity: O(n^2); Space Complexity: O(1)
void merge(std::vector<int>& nums, int low, int mid, int high, int* count){
    int i = low, j = mid+1;
    std::vector<int> arr;
    while (i <= mid && j <= high){
        if (nums[i] > nums[j]){
            *count = *count + (mid-i+1);
            arr.push_back(nums[j++]);
        }
        else{
            arr.push_back(nums[i++]);
        }
    }
    while (i <= mid){
        arr.push_back(nums[i++]);
    }
    while (j <= high){
        arr.push_back(nums[j++]);
    }
    for (int i = low; i <= high; ++i){
        *(nums.begin() + i) = arr[i-low];
    }
}
void divide(std::vector<int>& nums, int low, int high, int *count){
    if (low >= high){
        return;
    }
    int mid = (low+high)/2;
    divide(nums, low, mid, count);
    divide(nums, mid+1, high, count);
    merge(nums, low, mid, high, count);
}
int countInversions2(std::vector<int>& nums){
    int count = 0;
    divide(nums, 0, nums.size() - 1, &count);
    return count;
}
// Time Complexity: O(n log(n)); Space Complexity: O(n)
int main(){
    int n, num = 1;
    std::vector<int> nums;
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        nums.push_back(num);
    }
    int ans = countInversions2(nums);
    std::cout << "Inversions are: " << ans << std::endl;
    return 0;
}
