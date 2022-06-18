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
    int getLengthRecursive(TreeNode* root, int length) {
        if (root == nullptr) {
            return length;
        }
        
        return max(getLengthRecursive(root->left, length + 1), getLengthRecursive(root->right, length + 1));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int right = getLengthRecursive(root->right, 0);
        int left = getLengthRecursive(root->left, 0);

        int leftNodeDiameter = diameterOfBinaryTree(root->left);
        int rightNodeDiameter = diameterOfBinaryTree(root->right);
        
        return max(left + right, max(leftNodeDiameter, rightNodeDiameter));
    }
};

