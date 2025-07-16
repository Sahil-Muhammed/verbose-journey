// https://leetcode.com/problems/find-a-peak-element-ii/description/
// Attempt 1: Using binary search with max element among columns
// Outcome: Accepted
class Solution {
public:
    int findMax(vector<vector<int>> arr, int col){
        int max = 0, index = 0;
        for (int i = 0; i < arr.size(); ++i){
            //cout << i << " " << col << endl;
            if (arr[i][col] > max){
                index = i;
                max = arr[i][col];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int val = findMax(mat, mid);
            int left = -1, right = -1;
            if (mid >= 1){
                left = mat[val][mid - 1];
            }
            if (mid + 1 < mat[0].size()){
                right = mat[val][mid + 1];
            }
            if (mat[val][mid] > left && mat[val][mid] > right){
                return {val, mid};
            }
            else if (mat[val][mid] > left){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};
