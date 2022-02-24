class Solution {
public:
    string reverseWords(string s) {
        int right = s.size() - 1;
        int left = 0;
        string ret = "";
        while (right >= 0 && left >= 0) {
            while (right >= 0 && s[right] == ' ') {
                right--;
            }
            
            left = right;
            while (left >= 0 && s[left] != ' ') {
                left--;
            }
            
            left++;
            
            string word = s.substr(left, right - left + 1);
            if (word.size() > 0) {
                ret += word;
                ret += " ";
            }
            
            right = left - 1;
        }
        ret.pop_back();
        
        return ret;
    }
}
