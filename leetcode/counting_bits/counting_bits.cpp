class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for (int i = 0; i <= n; i++) {
            int num = i;
            int count = 0;
            while (num != 0) {
                if (num & 1 == 1) {
                    count++;
                }
                num = num >> 1;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
