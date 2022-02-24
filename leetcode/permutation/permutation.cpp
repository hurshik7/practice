class Solution {
public:
    void permuteRecursive(vector<vector<int>>& ret, vector<int>& nums, int k, vector<bool>& isVisit, vector<int>& temp) {
        if (k == nums.size()) {
            ret.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isVisit[i] == true) {
                continue;
            }
            isVisit[i] = true;
            temp.push_back(nums[i]);
            permuteRecursive(ret, nums, k + 1, isVisit, temp);
            temp.pop_back();
            isVisit[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> isVisit(nums.size(), false);
        vector<vector<int>> ret;
        vector<int> temp;
        permuteRecursive(ret, nums, 0, isVisit, temp);
        return ret;
    }
};
