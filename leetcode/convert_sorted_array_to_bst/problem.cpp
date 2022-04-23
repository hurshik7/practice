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
    void sortedArrayToBSTRecursive(TreeNode*& currentNode, vector<int>& nums, int start, int end) {
        if (start <= end) {
            int middle = (start + end) / 2;
            currentNode = new TreeNode(nums[middle]);
            sortedArrayToBSTRecursive(currentNode->left, nums, start, middle - 1);
            sortedArrayToBSTRecursive(currentNode->right, nums, middle + 1, end);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        sortedArrayToBSTRecursive(root, nums, 0, nums.size() - 1);
        return root;
    }
};
