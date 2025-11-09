#include <bits/stdc++.h>
using namespace std;
void PrintIntervals(vector<vector<int>>& interval){
    for (int i = 0; i < interval.size(); ++i){
        for (int j = 0; j < 2; ++j){
            cout << "Start: " << interval[i][0] << " End: " << interval[i][1] << endl;
        }
    }
}
void Greedy(vector<vector<int>> interval, vector<int>& startTime){
    sort(interval.begin(), interval.end(), [](vector<int>& a, vector<int>& b){ return a[1] < b[1];});
    // PrintIntervals(interval);
    vector<pair<int, int>> ans;
    while (interval.size() != 0){
        ans.push_back({interval[0][0], interval[0][1]});
        int i = 1;
        for (i = 1; i < interval.size(); ++i){
            if (interval[i][0] >= interval[0][1]){
                break;
            }
        }
        interval.erase(interval.begin(), interval.begin() + i);
    }

    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> interval(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i){
        cin >> interval[i][0] >> interval[i][1]; // startTime : EndTime
    }
    vector<int> startTime(n, 0);
    for (int i = 0; i < n; ++i){
        startTime[i] = interval[i][0];
    }
    Greedy(interval, startTime);
    return 0;
}
