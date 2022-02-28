class Solution {
public:
    void generateParenthesisRecursive(int n, int open, int close, string str, vector<string>& ret) {
        if (open < close) {
            return;
        }
        if (open == n && close == n) {
            ret.push_back(str);
            return;
        }
        
        if (open < n) {
            generateParenthesisRecursive(n, open + 1, close, str + "(", ret);
        }
        if (close < n) {
            generateParenthesisRecursive(n, open, close + 1, str + ")", ret);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string combi = "";
        generateParenthesisRecursive(n, 0, 0, combi, ret);
        return ret;
    }
};

