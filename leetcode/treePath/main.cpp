#include <string>
#include <vector>

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
      	string currentPath = "";
      	binaryTreePathRecursive(paths, root, currentPath);
      	return paths;
    }
    
    void binaryTreePathRecursive(vector<string>& paths, TreeNode* current, string currentPath) {
  		
      	currentPath += to_string(current->val);
      
      	if (current->left != nullptr) {
            if (currentPath[currentPath.size() - 1] != '>') {
                currentPath += "->";
            }
          	binaryTreePathRecursive(paths, current->left, currentPath); 
    	}
  		if (current->right != nullptr) {
            if (currentPath[currentPath.size() - 1] != '>') {
                currentPath += "->";
            }
          	binaryTreePathRecursive(paths, current->right, currentPath); 
    	}
  		else
    	{
            if (currentPath[currentPath.size() - 1] != '>') {
                paths.push_back(currentPath);
            }
          	return;
    	}
      	return;
	}
};
