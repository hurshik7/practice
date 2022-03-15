class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string ret = strs[0];
        
        for (int i = 1; i < strs.size(); ++i) {
            int j;
            for (j = 0; j < strs[i].size(); ++j) {
                if (ret[j] != strs[i][j]) {
                    break;  
                }
            }
            ret = ret.substr(0, j);
        }
        
        return ret;
    }
};
