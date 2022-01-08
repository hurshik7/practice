#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void indorderTraversalRecursive(TreeNode* root, vector<int>& v)
{
    if (root == nullptr) {
        return;
    } 
    
    indorderTraversalRecursive(root->left, v);
    v.push_back(root->val);
    indorderTraversalRecursive(root->right, v);
}

vector<int> inorderTraversal(TreeNode* root) 
{
    vector<int> ret;
    if (root == nullptr) {
        return ret;
    }

    indorderTraversalRecursive(root, ret);

    return ret;          
}

int main()
{
    TreeNode* testRoot = new TreeNode(1);
    testRoot->right = new TreeNode(2);
    testRoot->right->left = new TreeNode(3);

    vector<int> v = inorderTraversal(testRoot);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }    
    cout << endl;

    return 0;
}
