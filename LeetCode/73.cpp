// https://leetcode.com/problems/set-matrix-zeroes/description/
// Attempt 1: Brute force; store the zero elements in a vector of pairs; perform operation after entire matrix iteration
// Outcome: Accepted
class Solution {
public:
    void setZero(int i, int j, vector<vector<int>>& matrix){
        for (int k = 0; k < matrix[i].size(); ++k){
            matrix[i][k] = 0;
        }
        for (int k = 0; k < matrix.size(); ++k){
            matrix[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> pr1;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[i].size(); ++j){
                if (matrix[i][j] == 0){
                    pr1.insert({i, j});
                }
            }
        }
        for (auto it : pr1){
            cout << it.first << " " << it.second;
            setZero(it.first, it.second, matrix);
        }
    }
};
// Attempt 2: Store the column and row information in the first row and column with a separate variable for column 1
// Outcome: Accepted
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col1 = 1;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[i].size(); ++j){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if (j == 0){
                        col1 = 0;
                    }
                    else{
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (int i = matrix.size() - 1; i > 0; --i){
            for (int j = matrix[i].size() - 1; j > 0; --j){
                if (matrix[i][j] != 0){
                    if (matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0){
            for (int i = 0; i < matrix[0].size(); ++i){
                matrix[0][i] = 0;
            }
        }
        if (col1 == 0){
            for (int j = 0; j < matrix.size(); ++j){
                matrix[j][0] = 0;
            }
        }
    }
};
