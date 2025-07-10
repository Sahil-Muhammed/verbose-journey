// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
bool possible(std::vector<int> arr, int students, int maxDist){
    int j = 0, curr = 0, count = 1;
    while (j < arr.size()){
        curr += arr[j];
        if (curr > maxDist){
            //std::cout << "\t" << prev << " " << curr << " j = " << j << std::endl;
            curr = arr[j];
            count++;
        }
        j++;
    }
    std::cout << "\t\t" << count << " j = " << j << std::endl;
    if (count > students){
        return false;
    }
    return true;
}
int maxPages(std::vector<int> arr, int students, int max, int sum){
    int low = max, high = sum;
    while (low <= high){
        int mid = low + (high - low)/2;
        bool val = possible(arr, students, mid);
        std::cout << mid << " " << val << std::endl;
        if (val == true){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    int n, num = 0, students = 0;
    std::cin >> n >> students;
    if (students > n){
        std::cout << "-1" << std::endl;
    }
    std::vector<int> arr;
    int max = 0, sum = 0;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        sum += num;
        if (num > max){
            max = num;
        }
        arr.push_back(num);
    }
    int ans = maxPages(arr, students, max, sum);
    std::cout << ans << std::endl;
    return 0;
}