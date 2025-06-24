#include <bits/stdc++.h>

void Print(std::vector<int> arr){
    for (auto it : arr){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}
int main(){
    int n1, n2, num = 0;
    std::cin >> n1 >> n2;
    std::vector<int> arr1, arr2;
    for (int i = 0; i < n1; ++i){
        std::cin >> num;
        arr1.push_back(num);
    }
    for (int j = 0; j < n2; ++j){
        std::cin >> num;
        arr2.push_back(num);
    }
    std::vector<int> intersection;
    int i  = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()){
        if (arr1[i] < arr2[j]){
            i++;
        }
        else if (arr1[i] > arr2[j]){
            j++;
        }
        else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    Print(intersection);
    return 0;
}
