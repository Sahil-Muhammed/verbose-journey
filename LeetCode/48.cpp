// https://leetcode.com/problems/rotate-image/description/
// Attempt 1: Transpose and reverse
// Outcome: Accepted
class Solution {
public:
    void swap(int* a, int *b){
        int temp = *a;
        *a = *b;
        temp = *b;
    }
    void transpose(vector<vector<int>>& matrix){
        for (int i = 0; i < matrix.size() - 1; ++i){
            for (int j = i+1; j < matrix[i].size(); ++j){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i = 0; i < matrix.size(); ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
