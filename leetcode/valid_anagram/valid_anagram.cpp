class Solution {
public:
    bool isAnagram(string s, string t) {
        string temp = s;
        
        for (int i = 0; i < t.length(); ++i) {
            size_t index = temp.find_first_of(t[i]);
            if (index >= temp.length()) {
                return false;
            }
            temp.erase(index, 1);
        }
        if (temp.length() > 0) {
            return false;
        }
        return true;
    }
};
