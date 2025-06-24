#include <bits/stdc++.h>

// Idea: Divide and merge. Merging requires clever use of indices and a temporary array/vector.

void merge(std::vector<int> &arr, int low, int mid, int high){
    int i = low, j = mid+1;
    std::vector<int> temp;
    while (i <= mid && j <= high){
        if (arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid){
        temp.push_back(arr[i++]);
    }
    while (j <= high){
        temp.push_back(arr[j++]);
    }
    for (int i = low; i <= high; ++i){
        arr[i] = temp[i-low];
    }
}
void divide(std::vector<int> &arr, int low, int high){
    if (low >= high){
        return;
    }
    int mid = (low+high)/2;
    divide(arr, low, mid);
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void Print(std::vector<int> arr){
    for (auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}
int main(){
    int n, num = 0;
    std::cin >> n;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    divide(arr, 0, n-1);
    Print(arr);
    return 0;
}

// Time complexity: O(n * log n) --> Merging is an iterative process O(n) and dividing is a recursive process taking about n * log n processes
