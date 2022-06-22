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
#include <queue>

class Solution {
public:
    void BFSRecursive(vector<vector<int>>& v, queue<TreeNode*> q) {
        if (q.size() == 0) {
            return;
        }
        
        vector<int> currentStage;
        queue<TreeNode*> nextQ;
    
        while (q.size() != 0) {
            TreeNode* current = q.front();
            q.pop();
            currentStage.push_back(current->val);
            if (current->left != nullptr) {
                nextQ.push(current->left);
            }
            if (current->right != nullptr) {
                nextQ.push(current->right);
            }
        }
        v.push_back(currentStage);
        BFSRecursive(v, nextQ);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
            BFSRecursive(ret, q);   
        }
        return ret;
    }
};
