#include <bits/stdc++.h>
void stackSort(std::stack<int>& stk, int x){
    if (stk.empty() || x < stk.top()){
        stk.push(x);
        return;
    }
    int temp = stk.top();
    stk.pop();
    stackSort(stk, x);
    stk.push(temp);
}
void sort(std::stack<int>& stk){
    if (!stk.empty()){
        int x = stk.top();
        stk.pop();
        sort(stk);
        stackSort(stk, x);
    }
}
int main(){
    int n, num = 0;
    std::cin >> n;
    std::stack<int> stk;
    for (int i = 0; i < n; ++i){
        std::cin >> num;
        stk.push(num);
    }
    sort(stk);
    for (int i = 0; stk.empty() != true; ++i){
        num = stk.top();
        stk.pop();
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
