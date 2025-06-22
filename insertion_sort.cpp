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

void sorting(std::vector<int> &arr){
    for (int i = 1; i < arr.size(); ++i){  // i is supposed to be initialized to 1, but it can be initialized to 0 as well, in that case the condition for the inner loop should begin with "j >= 0" so that the compiler will always not run the inner loop when i = 0
        int pivot = arr[i], j = i-1;
        for (j = i-1; j >= 0 && pivot < arr[j]; --j){
            arr[j+1] = arr[j];
        }
        arr[j+1] = pivot;
    }
}

void asc_sorting_reverse(std::vector<int> &arr){
    for (int i = arr.size() - 2; i >= 0; --i){
        int pivot = arr[i], j = i+1;
        for (j = i+1; j < arr.size() && pivot > arr[j]; ++j){
            arr[j-1] = arr[j];
        }
        arr[j-1] = pivot;
    }
}
void desc_sorting_reverse(std::vector<int> &arr){
    for (int i = arr.size()-2; i > -1; --i){
        int pivot = arr[i], j = i + 1;
        for (j = i + 1; j < arr.size() && pivot < arr[j]; ++j){
            arr[j-1] = arr[j];
        }
        arr[j-1] = pivot;
    }
}
int main(){
    int n, num = 0;
    std::cin >> n;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    desc_sorting_reverse(arr);
    Print(arr);
    return 0;
}

// Time complexity: Best case --> O(n); no swaps but iterates through each element to check condition once
//                  Average case --> O(n^2); for each i, half the elements behind it are swapped
//                  Worst case --> O(n^2); all elements are swapped for every i
