#include <bits/stdc++.h>

// Insertion sort idea: Put each element in its right place; In the ith iteration, put the element arr[i] in its correct position in the subarray arr[0...i]

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertion(std::vector<int> &arr){
    for (int i = 1; i < arr.size(); ++i){
        int toBeSwapped = *(arr.begin() + i);
        int j = i - 1;
        for (j = i-1; j >= 0 && toBeSwapped < *(arr.begin() + j); --j){
            // swap(&(*(arr.begin() + j)), &toBeSwapped);
            // toBeSwapped = *(arr.begin() + j - 1);
            *(arr.begin() + j + 1) = *(arr.begin() + j);
        }
        arr[j+1] = toBeSwapped;
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
    insertion(arr);
    Print(arr);
    return 0;
}
