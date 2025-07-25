#include <bits/stdc++.h> 
void findPath(int i, int j, std::string path, std::vector<std::string>& vis, std::vector<std::string> maze, std::vector<std::string>& ans){
    //std::cout << i << " " << j << std::endl;
    if (i >= maze.size() || j >= maze.size() || i < 0 || j < 0 || maze[i][j] == '0' || vis[i][j] == '1'){
        return;
    }
    if (i == maze.size() - 1 && j == maze.size() - 1 && maze[i][j] == '1'){
        ans.push_back(path);
        return;
    }
    vis[i][j] = '1';
    findPath(i+1, j, path+"D", vis, maze, ans);
    findPath(i-1, j, path+"U", vis, maze, ans);
    findPath(i, j+1, path+"R", vis, maze, ans);
    findPath(i, j-1, path+"L", vis, maze, ans);
    vis[i][j] = '0';
}
int main(){
    int n;
    std::cin >> n;
    std::vector<std::string> maze;
    std::string zeroes = "";
    for (int i = 0; i < n; ++i){
        std::string temp = "";
        std::cin >> temp;
        zeroes += "0";
        maze.push_back(temp);
    }
    std::vector<std::string> vis(n, zeroes);
    std::vector<std::string> ans;
    //std::string path = "";
    findPath(0, 0, "", vis, maze, ans);
    for (int i = 0; i < ans.size(); ++i){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
// 0 0 0 0 
// 0 0 1 1
// 0 0 1 1
// 0 0 0 0