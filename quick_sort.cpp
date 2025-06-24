#include <bits/stdc++.h>
#include <chrono>

// Idea: Position (the pivot) and call recursively

void swap(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
int PartitionIndex(std::vector<int> &arr, int low, int high){
    int i = low, j = high;
    int pivot = arr[low];
    while (i < j){
        while (pivot >= arr[i] && i <= high-1){
            i++;
        }
        while (pivot <= arr[j] && j >= low+1){
            j--;
        }
        if (i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}
void QuickSort(std::vector<int> &arr, int low, int high){
    if (low >= high){
        return;
    }
    int PIndex = PartitionIndex(arr, low, high);
    QuickSort(arr, low, PIndex-1);
    QuickSort(arr, PIndex+1, high);
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
    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(arr, 0, n-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    Print(arr);
    std::cout << "Time: " << duration.count() << " nanoseconds" << std::endl;
    return 0;
}

// Time complexity: O(n * log n) in the average case, but O(n^2) in the worst case when pivot is chosen such that the partitions are 'one-sided' throughout.
// Note: Sometimes preferred over merge sort because of taking O(log n) space complexity from the recursion calls.
