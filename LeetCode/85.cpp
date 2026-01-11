// https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11
// Attempt 1: Brute force
// Outcome: TLE; 70/75
class Solution {
public:
    int countOnes(vector<vector<char>>& matrix, int startX, int startY, int endX, int endY){
        int count = 0;
        for (int i = startX; i <= endX; ++i){
            for (int j = startY; j <= endY; ++j){
                if (matrix[i][j] == '0'){
                    return 0;
                }
                else{
                    count++;
                }
            }
        }
        return count;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxCount = 0, rowLen = matrix[0].size(), colLen = matrix.size();
        for (int i = 0; i < colLen; ++i){
            for (int j = 0; j < rowLen; ++j){
                for (int k = i; k < colLen; ++k){
                    for (int l = j; l < rowLen; ++l){
                        int temp = countOnes(matrix, i, j, k, l);
                        // cout << i << " " << j << " " << k << " " << l << " count = " << temp << endl;
                        maxCount < temp ? maxCount = temp : maxCount = maxCount;
                    }
                }
            }
        }
        return maxCount;
    }
}; 
