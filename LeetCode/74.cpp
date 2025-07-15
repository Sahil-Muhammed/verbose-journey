// https://leetcode.com/problems/search-a-2d-matrix/description/
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
// Attempt 2: Binary search
// Outcome: Accepted
class Solution {
public:
    int binSearch(vector<int> arr, int target){
        int low = 0, high = arr.size() - 1;
        if (arr[0] > target){
            return -1;
        }
        if (arr[arr.size() - 1] < target){
            return 2;
        }
        while (low <= high){
            int mid = (low + high) / 2;
            if (arr[mid] > target){
                high = mid - 1;
            }
            else if (arr[mid] < target){
                low = mid + 1;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] || target > matrix[matrix.size() - 1][matrix[0].size() - 1]){
            return false;
        }
        int low = 0, high = matrix.size() - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int val = binSearch(matrix[mid], target);
            //cout << val << endl;
            if (val == 2){
                low = mid + 1;
            }
            else if (val == -1){
                high = mid - 1;
            }
            else if (val == 1){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};
// Attempt 3: Binary search
// Outcome: Accepted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = (matrix.size() * matrix[0].size()) - 1;
        while (low <= high){
            int mid = (low + high) / 2;
            int row = mid / matrix[0].size();
            int column = mid % matrix[0].size();
            if (matrix[row][column] == target){
                return true;
            }
            else if (matrix[row][column] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};
