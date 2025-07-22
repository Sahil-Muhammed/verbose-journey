// https://leetcode.com/problems/palindrome-partitioning/description/
// Attempt 1: Using recursion (backtracking)
// Outcome: Accepted
class Solution {
public:
    bool isPalin(string ds){
        int low = 0, high = ds.size() - 1;
        while (low <= high){
            if (ds[low] == ds[high]){
                low++;
                high--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void recursiveTree(vector<string>& ds, string s, vector<vector<string>>& ans){
        for (int i = 0; i < ds.size(); ++i){
            cout << ds[i] << " ";
        }
        cout << endl;
        if (s == ""){
            ans.push_back(ds);
            return;
        }
        // if (pos >= s.size()){
        //     return;
        // }

        for (int i = 0; i < s.size(); ++i){
            if (isPalin(s.substr(0, i+1)) != true){
                continue;
            }
            ds.push_back(s.substr(0, i+1));
            recursiveTree(ds, s.substr(i+1, s.size() - i - 1), ans);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        recursiveTree(ds, s, ans);
        return ans;
    }
};
