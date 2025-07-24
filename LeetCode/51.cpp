class Solution {
public:
    void PrintTable(vector<string> board){
        for (int i = 0; i < board.size(); ++i){
            cout << board[i] << endl;
        }
    }
    void fillTable(vector<string>& board, int i, int j, int num, bool remove) {
    char mark = (char)(num + '0');

    int n = board.size();

    // Directions: {rowDelta, colDelta}
    vector<pair<int, int>> directions = {
        {1, 0},   // down
        {0, 1},   // right
        {1, 1},   // down-right
        {-1, -1}, // up-left
        {-1, 1},  // up-right
        {1, -1}   // down-left
    };

    // Mark the current row and column
    for (int row = 0; row < n; ++row) {
        if (row == i) continue;
        if (remove) {
            if (board[row][j] == mark) board[row][j] = '.';
        } else {
            if (board[row][j] == '.') board[row][j] = mark;
        }
    }

    for (int col = 0; col < n; ++col) {
        if (col == j) continue;
        if (remove) {
            if (board[i][col] == mark) board[i][col] = '.';
        } else {
            if (board[i][col] == '.') board[i][col] = mark;
        }
    }

    // Diagonals
    for (auto [dx, dy] : directions) {
        int row = i + dx, col = j + dy;
        while (row >= 0 && row < n && col >= 0 && col < n) {
            if (remove) {
                if (board[row][col] == mark) board[row][col] = '.';
            } else {
                if (board[row][col] == '.') board[row][col] = mark;
            }
            row += dx;
            col += dy;
        }
    }
}

    void recursiveTree(int queens, vector<string>& board, vector<vector<string>>& ans, int i, int j){
        if (board[i][j] != '.'){
            return;
        }
        board[i][j] = (char)'Q';
        fillTable(board, i, j, board.size() - queens, false);
        if (queens == 1){
            vector<string> temp = board;
            for (int i = 0; i < board.size(); ++i){
                for (int j = 0; j < board[i].size(); ++j){
                    if (isdigit(temp[i][j])){
                        temp[i][j] = (char)'.';
                    }
                }
            }
            ans.push_back(temp);
            return;
        }
        PrintTable(board);
        bool found = false;
        for (int row = 0; row < board.size(); ++row){
            for (int col = 0; col < board[i].size(); ++col){
                if (board[row][col] == (char)'.'){
                    found = true;
                    recursiveTree(queens-1, board, ans, row, col);
                }
            }
        }
        // if (found == false && queens == 1){
        //     vector<string> temp = board;
        //     for (int i = 0; i < board.size(); ++i){
        //         for (int j = 0; j < board[i].size(); ++j){
        //             if (isdigit(temp[i][j])){
        //                 temp[i][j] = (char)'.';
        //             }
        //         }
        //     }
        //     ans.push_back(temp);
        //     return;
        // }
        board[i][j] = (char)'.';
        fillTable(board, i, j, board.size() - queens, true);
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for (int i = 0; i < n; ++i){
            string temp = "";
            for (int j = 0; j < n; ++j){
                temp += '.';
            }
            board.push_back(temp);
        }
        PrintTable(board);
        for (int i = 0; i < n; ++i){
            recursiveTree(n, board, ans, 0, i);
            PrintTable(board);
        }
        for (int i = 0; i < ans.size(); ++i){
            for (int j = 0; j < ans[i].size(); ++j){
                for (int k = 0; k < ans[i][j].size(); ++k)
                if (isdigit(ans[i][j][k])){
                    ans[i][j][k] = (char)'.';
                }
            }
        }
        return ans;
    }
};