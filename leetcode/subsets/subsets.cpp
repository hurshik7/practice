class Solution {
public:
    void recursive(vector<vector<int>>& v, vector<int>& temp, vector<int>& nums, int current) {
        for (int i = current; i < nums.size(); ++i) {
            temp.push_back(nums[i]);
            v.push_back(temp);
            recursive(v, temp, nums, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        ret.push_back(temp);
        recursive(ret, temp, nums, 0);
        return ret;
    }
};
