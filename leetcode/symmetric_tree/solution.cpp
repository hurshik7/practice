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
    void preorderRecursive(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        if (root->left != nullptr) {
            preorderRecursive(root->left, v);
        } else {
            v.push_back(0);
        }
        if (root->right != nullptr) {
            preorderRecursive(root->right, v);   
        } else {
            v.push_back(0);
        }
    }
    
    void postorderRecursive(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            postorderRecursive(root->left, v);
        } else {
            v.push_back(0);
        }
        if (root->right != nullptr) {
            postorderRecursive(root->right, v);   
        } else {
            v.push_back(0);
        }
        v.push_back(root->val);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }  

        vector<int> pre;
        vector<int> post;
        if (root->left != nullptr) {
            preorderRecursive(root->left, pre);
        }
        if (root->right != nullptr) {
            postorderRecursive(root->right, post);   
        }
        
        if (pre.size() != post.size()) {
            return false;
        }
        for (size_t i = 0; i < pre.size(); ++i) {
            if (pre[i] != post[post.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
