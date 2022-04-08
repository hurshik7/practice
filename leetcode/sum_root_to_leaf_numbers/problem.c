/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumNumbersRecursive(struct TreeNode* currentNode, int currentSum) {
    int sum = (currentSum * 10) + currentNode->val;
    if (currentNode->left == NULL && currentNode->right == NULL) {
        return sum;
    } else if (currentNode->left != NULL && currentNode->right == NULL) {
        return sumNumbersRecursive(currentNode->left, sum);
    } else if (currentNode->left == NULL && currentNode->right != NULL) {
        return sumNumbersRecursive(currentNode->right, sum);
    } else {
        return sumNumbersRecursive(currentNode->left, sum) + sumNumbersRecursive(currentNode->right, sum);   
    }
}

int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    return sumNumbersRecursive(root, 0);
}
