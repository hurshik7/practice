class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp;
        vector<bool> isVisit(n + 1, false);
        combineRecursive(ret, 1, n, k, temp, isVisit);
        return ret;
    }
    
    void combineRecursive(vector<vector<int>>& ret, int start, int n, int k, vector<int>& temp, vector<bool>& isVisit) {
        if (k == temp.size()) {
            ret.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++) {
            if (isVisit[i] == true) {
                continue;
            }
            isVisit[i] = true;
            temp.push_back(i);
            combineRecursive(ret, i + 1, n, k, temp, isVisit);
            temp.pop_back();
            isVisit[i] = false;
        }
    }
};
