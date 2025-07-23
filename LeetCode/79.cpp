// https://leetcode.com/problems/word-search/description/
// Attempt 1: Using recursion (backtracking), marking cells which are visited
// Outcome: Accepted
class Solution {
public:
    void PrintMatrix(vector<vector<char>> board){
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    void recursiveTree(string word, int i, int j, vector<vector<char>>& board, bool& found, vector<int>& ans){
        //PrintMatrix(board);
        //cout << "Row: " << i << " Column: " << j << endl;
        if (word == ""){
            for (int i = 0; i < ans.size(); ++i){
                cout << ans[i] << " ";
            }
            cout << endl;
            found = true;
            return;
        }
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0){
            return;
        }
        //cout << "After second base case" << endl;
        //for (int row = i; row < board.size(); ++row){
            //for (int col = j; col < board[i].size(); ++col){
                if (board[i][j] == word[0]){
                    char temp = board[i][j];
                    ans.push_back(i);
                    ans.push_back(j);
                    board[i][j] = '.';
                    recursiveTree(word.substr(1, word.size() - 1), i + 1, j, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i, j + 1, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i - 1, j, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i, j - 1, board, found, ans);
                    if (found == true){
                        return;
                    }
                    board[i][j] = temp;
                    ans.pop_back();
                    ans.pop_back();
                }
            //}
        //}
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        vector<int> ans;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                recursiveTree(word, i, j, board, found, ans);
                if (found == true){
                    return true;
                }
            }
        }
        return found;
    }
};
// Attempt 2: Optimized previous program by performing a minimum character frequency check
// Outcome: Accepted
class Solution {
public:
    // void PrintMatrix(vector<vector<char>> board){
    //     for (int i = 0; i < board.size(); ++i){
    //         for (int j = 0; j < board[i].size(); ++j){
    //             cout << board[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    void recursiveTree(string word, int i, int j, vector<vector<char>>& board, bool& found, vector<int>& ans){
        //PrintMatrix(board);
        //cout << "Row: " << i << " Column: " << j << endl;
        if (word == ""){
            for (int i = 0; i < ans.size(); ++i){
                cout << ans[i] << " ";
            }
            cout << endl;
            found = true;
            return;
        }
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0){
            return;
        }
        //cout << "After second base case" << endl;
        //for (int row = i; row < board.size(); ++row){
            //for (int col = j; col < board[i].size(); ++col){
                if (board[i][j] == word[0]){
                    char temp = board[i][j];
                    ans.push_back(i);
                    ans.push_back(j);
                    board[i][j] = '.';
                    recursiveTree(word.substr(1, word.size() - 1), i + 1, j, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i, j + 1, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i - 1, j, board, found, ans);
                    if (found == true){
                        return;
                    }
                    recursiveTree(word.substr(1, word.size() - 1), i, j - 1, board, found, ans);
                    if (found == true){
                        return;
                    }
                    board[i][j] = temp;
                    ans.pop_back();
                    ans.pop_back();
                }
            //}
        //}
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        int size = board.size() * board[0].size();
        if (size < word.size()){
            return false;
        }
        unordered_map<char, int> wordFreq, boardFreq;
        for (int i = 0; i < word.size(); ++i){
            wordFreq[word[i]]++;
        }
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                boardFreq[board[i][j]]++;
            }
        }

        for (int i = 0; i < word.size(); ++i){
            if (wordFreq[word[i]] > boardFreq[word[i]]){
                return false;
            }
        }
        vector<int> ans;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[i].size(); ++j){
                recursiveTree(word, i, j, board, found, ans);
                if (found == true){
                    return true;
                }
            }
        }
        return found;
    }
};
