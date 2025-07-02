#include <bits/stdc++.h>

void misrep1(std::vector<int> arr){
    int missing = -1, repeating = -1;
    for (int i = 1; i <= arr.size(); ++i){
        int count = 0;
        for (int j = 0; j < arr.size(); ++j){
            if (arr[j] == i){
                count += 1;
            }
        }
        std::cout << i << " " << count << std::endl;
        if (count == 2){
            repeating = i;
        }
        else if (count == 0){
            missing = i;
        }
        if (repeating != -1 && missing != -1){
            break;
        }
    }
    std::cout << "Missing: " << missing << std::endl;
    std::cout << "Repeating: " << repeating << std::endl;
}
// Time Complexity: O(n^2); Space Complexity: O(1)
void misrep2(std::vector<int> arr){
    int hash[arr.size() + 1] = {0};
    for (int i = 0; i < arr.size(); ++i){
        hash[arr[i]]++;
    }
    int mis = -1, rep = -1;
    for (int i = 1; i <= arr.size(); ++i){
        if (hash[i] == 0){
            mis = i;
        }
        else if (hash[i] == 2){
            rep = i;
        }
        if (mis != -1 && rep != -1){
            break;
        }
    }
    std::cout << "Missing: " << mis << std::endl;
    std::cout << "Repeating: " << rep << std::endl;
}
// Time Complexity: O(n) + O(n); Space Complexity: O(n)
void misrep3(std::vector<int> arr){
    int x = -1, y = -1;
    int n = arr.size();
    int sum = (n) * (n + 1) / 2, arrSum = 0, arrSquareSum = 0;
    for (int i = 0; i < n; ++i){
        arrSum += arr[i];
        arrSquareSum += (arr[i] * arr[i]);
    }
    int xMinusY  = arrSum - sum;
    int xPlusY = (arrSquareSum - ((n * (n+1) * (2 * n + 1) ) / 6)) / xMinusY;
    x = (xMinusY + xPlusY) / 2;
    y = x - xMinusY;
    std::cout << "Missing: " << y << std::endl;
    std::cout << "Repeating: " << x << std::endl;
}
// Time Complexity: O(n); Space Complexity: O(1)
int main(){
    int n, num = 1;
    std::cin >> n;
    std::vector<int> arr;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        arr.push_back(num);
    }
    misrep3(arr);
    return 0;
}
