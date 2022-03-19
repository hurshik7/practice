#define SIZE (26)

class Solution {
public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length()) {
                return false;
            }
            int counting[SIZE] = {0, };   
            
            for (int i = 0; i < s.length(); ++i) {
                counting[s[i] - 'a']++;
                counting[t[i] - 'a']--;
            }
            
            for (int i = 0; i < SIZE; ++i) {
                if (counting[i] != 0) {
                    return false;
                }
            }
            return true;
        }
};
