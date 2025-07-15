// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Attempt 1: Brute force
// Outcome: Accepted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[i].size(); ++j){
                if (matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};
// Attempt 2: Binary Search
// Outcome: Accepted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, column = matrix[0].size() - 1;
        while (row < matrix.size() && column >= 0){
            if (matrix[row][column] == target){
                return true;
            }
            else if (matrix[row][column] < target){
                row++;
            }
            else{
                column--;
            }
        }
        return false;
    }
};
