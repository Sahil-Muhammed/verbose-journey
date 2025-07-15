#include <bits/stdc++.h>
int binSearch(std::vector<int> arr){
    int low = 0, high = arr.size() - 1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] > 0){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    //std::cout << "Number of 1s is " << arr.size() - low << std::endl;
    return arr.size() - low;
}
int count(std::vector<std::vector<int>> arr){
    int max = 0, maxCount = 0;
    for (int i = 0; i < arr.size(); ++i){
        int temp = binSearch(arr[i]);
        if (temp > maxCount){
            max = i;
            maxCount = temp;
        }
    }
    if (maxCount == 0){
        return -1;
    }
    return max;
}
int main(){
    int n, num = 0;
    std::vector<std::vector<int>> matrix;
    std::cin >> n;
    for (int i = 0; i < n; ++i){
        std::vector<int> temp;
        for (int j = 0; j < n; ++j){
            std::cin >> num;
            temp.push_back(num);
        }
        matrix.push_back(temp);
    }
    int ans = count(matrix);
    std::cout << ans << std::endl;
    return 0;
}
