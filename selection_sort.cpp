#include <bits/stdc++.h>

// Selection sort idea: Swap the minimum element in the array[i..n] to i-1th position

void swap(int a, int b, std::vector<int> &arr){
    int temp = *(arr.begin()+a);
    *(arr.begin()+a) = *(arr.begin() + b);
    *(arr.begin() + b) = temp;
}

int main(){
    int n, num = 0;
    std::cin >> n;
    std::vector<int> arr;
    for (int k = 0; k < n; ++k){
        std::cin >> num;
        arr.push_back(num);
    }

    for (int i = 0; i < n-1; ++i){
        int min = i;
        for (int j = i; j < n; ++j){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        swap(i, min, arr);
    }

    for (auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}
