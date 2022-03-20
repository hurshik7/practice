class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> temp;
        temp.push_back(1);
        v.push_back(temp);
        temp.clear();
        
        for (int i = 1; i < numRows; ++i) {
            temp.clear();
            for (int j = 0; j < i + 1; ++j) {
                if (j == 0 || j == i) {
                    temp.push_back(1);
                    continue;
                }
                int lti = j - 1;
                int rti = j;
                int lt = 0;
                int rt = 0;
                if (lti >= 0) {
                    lt = v[i - 1][lti];
                }
                if (rti <= i - 1) {
                    rt = v[i - 1][rti];
                }
                temp.push_back(lt + rt);
            }
            v.push_back(temp);
        }
        
        return v;
    }
};
