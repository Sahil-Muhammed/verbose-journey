// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06
// Attempt 1: Breadth First Search
// Outcome: Accepted; 41/41

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1, maxLevel = 1, maxSum = INT_MIN;
        vector<TreeNode*> arr;
        arr.push_back(root);
        while (arr.size() > 0){
            int sum = 0, size = arr.size();
            for (int i = 0; i < size; ++i){
                sum += arr[i] == nullptr ? 0 : arr[i]->val;
                if (arr[i]->left != nullptr)
                    arr.push_back(arr[i]->left);
                if (arr[i]->right != nullptr)
                    arr.push_back(arr[i]->right);
            }
            if (sum > maxSum){
                maxSum = sum;
                maxLevel = level;
            }  
            arr.erase(arr.begin(), arr.begin() + size);
            // update array with next level elements
            // cout << sum << " is the sum at level " << level << endl;
            level++;
        }

        return maxLevel;
    }
};
