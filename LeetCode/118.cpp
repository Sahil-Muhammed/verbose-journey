
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> oen;
        oen.push_back(1);
        pascal.push_back(oen);
        if (numRows >= 2){
            oen.push_back(1);
            pascal.push_back(oen);
        }
        while (pascal.size() < numRows){
            vector<int> puthan;
            for (int i = 1; i <= pascal[pascal.size() - 1].size() - 1; ++i){
                puthan.push_back(pascal[pascal.size() - 1][i] + pascal[pascal.size() - 1][i-1]);
            }
            puthan.insert(puthan.begin(), 1);
            puthan.insert(puthan.end(), 1);
            pascal.push_back(puthan);
        }
        return pascal;
    }
};