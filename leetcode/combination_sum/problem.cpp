class Solution {
public:
    void recursive(vector<vector<int>>& ret, vector<int>& candidates, vector<int>& temp, int newTarget, int current) {
        if (newTarget == 0) {
            ret.push_back(temp);
        }
        
        for (int i = current; i >= 0; --i) {
            if (candidates[i] <= newTarget) {
                temp.push_back(candidates[i]);
                recursive(ret, candidates, temp, newTarget - candidates[i], i);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> temp;
        recursive(ret, candidates, temp, target, candidates.size() - 1);
        return ret;
    }
};
