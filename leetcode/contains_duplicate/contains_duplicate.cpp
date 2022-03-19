class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> temp;
        for (int i = 0; i < nums.size(); ++i) {
            if (find(temp.begin(), temp.end(), nums[i]) == temp.end()) {
                temp.push_back(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
