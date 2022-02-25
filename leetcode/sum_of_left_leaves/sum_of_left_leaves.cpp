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
    int sumOfLeftLeavesRecursive(TreeNode* root, bool fromRight) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr && fromRight == true) {
            return root->val;
        }
        
        return sumOfLeftLeavesRecursive(root->left, true) + sumOfLeftLeavesRecursive(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = sumOfLeftLeavesRecursive(root, false);
        return sum;
    }
};
