// https://leetcode.com/problems/spiral-matrix/
// Attempt 1: Use pointers left, right, top, and bottom
// Outcome: Accepted
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> store1;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        while (left <= right && top <= bottom){
            for (int i = left; i <= right; ++i){
                store1.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; ++i){
                store1.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom){
                for (int i = right; i >= left; --i){
                    store1.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right){
                for (int i = bottom; i >= top; --i){
                    store1.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return store1;
    }
};
