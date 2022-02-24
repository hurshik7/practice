class Solution {
public:
    string reverseWords(string s) {
        const char* cStr = s.c_str();
        char buffer[10001];
        buffer[10000] = '\0';
        strcpy(buffer, cStr);
        
        vector<string> words;
        char* tok;
        tok = strtok(buffer, " ");
        while (tok != NULL) {
            string temp(tok);
            words.push_back(temp);
            tok = strtok(NULL, " ");
        }
        
        string ret(words[words.size() - 1]);
        for(int i = words.size() - 2; i >= 0; i--) {
            ret += ' ';
            ret += words[i];
        }
        
        return ret;
    }
};
