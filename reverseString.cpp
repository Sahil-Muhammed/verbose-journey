#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int low = 0, high = s.size() - 1;
    while (low < high){
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp;
        low++;
        high--;
    }
    cout << s << endl;
    return 0;
}
