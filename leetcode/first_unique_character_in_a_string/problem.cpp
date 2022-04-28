class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); ++i) {
            map[s[i]] += 1;
        }
        
        int index = 100000;
        int tempIndex = -1;
        for (auto e : map) {
            if (e.second == 1) {
                tempIndex = -1;
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] == e.first) {
                            tempIndex = i;
                    }
                }
                index = tempIndex < index ? tempIndex : index;
            }
        }
        if (index == 100000) {
            return -1;
        }
        return index;
    }
};
