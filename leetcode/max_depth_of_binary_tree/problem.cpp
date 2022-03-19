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
    int maxDepthRecursive(TreeNode* root, int count) {
        if (root == nullptr) {
            return count - 1;
        }
        
        return max(maxDepthRecursive(root->left, count + 1), maxDepthRecursive(root->right, count + 1));
    }
    
    int maxDepth(TreeNode* root) {
        int count = 1;
        
        return maxDepthRecursive(root, count);
    }
};
