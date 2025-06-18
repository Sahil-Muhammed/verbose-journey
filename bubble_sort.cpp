#include <bits/stdc++.h>

// Bubble sort idea: Keep swapping in each iteration through the array, the ith iteration will ensure that the n-i+1th element is in the right position.

void swap(int i, int j, std::vector<int> &arr){
    int temp = *(arr.begin() + i);
    *(arr.begin() + i) = *(arr.begin() + j);
    *(arr.begin() + j) = temp;
}
void bubble(std::vector<int> &arr){
    for (int i = 0; i < arr.size() - 1; ++i){
        for (int j = 0; j < arr.size() - i - 1; ++j){
            if (*(arr.begin() + j) > *(arr.begin() + j + 1)){
                swap(j, j+1, arr);
            }
        }
    }
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

    bubble(arr);
    Print(arr);
    return 0;
}
