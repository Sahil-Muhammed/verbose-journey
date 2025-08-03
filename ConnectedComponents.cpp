#include <bits/stdc++.h>
void PrintGraph(std::vector<int>* adj, int n){
    for (int i = 1; i <= n; ++i){
        std::cout << i << " ";
        for (int j = 0; j < adj[i].size(); ++j){
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void traverse(std::vector<int>* adj, std::vector<int>& visited, int i){
    visited[i] = 1;
    for (int j = 0; j < adj[i].size(); ++j){
        if (visited[adj[i][j]] == 0){
            traverse(adj, visited, adj[i][j]);
        }
    }
}
void PrintVisited(std::vector<int> visited){
    std::cout << std::endl;
    for (int i = 0; i < visited.size(); ++i){
        std::cout << visited[i] << " ";
    }
    std::cout << std::endl;
}
int ConnectedComp(std::vector<int>* adj, int n){
    std::vector<int> visited(n+1, 0);
    int count = 0;
    for (int i = 1; i <= n; ++i){
        PrintVisited(visited);
        if (visited[i] == 0){
            count++;
            traverse(adj, visited, i);
        }
    }
    return count;
}
int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n+1];
    for (int i = 1; i <= m; ++i){
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::cout << std::endl;
    PrintGraph(adj, n);
    std::cout << "The number of connected components is " << ConnectedComp(adj, n) << std::endl;
    return 0;
}
