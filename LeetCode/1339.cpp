// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07
// Attempt 1: Inorder Traversal + BFS
// Outcome: Accepted

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
const int MOD = 1e9 + 7;
class Solution {
public:
    unordered_map<TreeNode*, long> mapSum;
    int SumOfNodes(TreeNode* root){
        int sum = 0;
        if (root == nullptr){
            return sum;
        }
        TreeNode* temp = root;
        sum += root->val;
        sum += SumOfNodes(root->left);
        sum += SumOfNodes(root->right);
        return mapSum[root] = sum;
    }
    int maxProduct(TreeNode* root) {
        long totalSum = 0;
        long maxProduct = 1;
        TreeNode* temp = root;
        totalSum = SumOfNodes(temp);

        vector<TreeNode*> arr;
        arr.push_back(root);
        while (arr.size() > 0){
            int size = arr.size();
            for (int i = 0; i < size; ++i){
                long sumAtThisNode = mapSum[arr[i]];
                // SumOfNodes(arr[i], &sumAtThisNode);
                long prod = (long)(totalSum - sumAtThisNode) * (long)(sumAtThisNode);
                if (prod > maxProduct)  maxProduct = prod;
                if (arr[i]->left != nullptr){
                    arr.push_back(arr[i]->left);
                }
                if (arr[i]->right != nullptr){
                    arr.push_back(arr[i]->right);
                }
            }
            arr.erase(arr.begin(), arr.begin() + size);
        }
        return maxProduct % MOD;
    }
};
