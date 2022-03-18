class Solution {
public:
    int mySqrt(int x) {
        unsigned int ret = 0;
        if (x == 1) {
            return 1;
        }
        for (unsigned int i = 1; i <= x; ++i) {
            if (i * i == x) {
                ret = i;
                break;
            } else if (i * i > x) {
                ret = i - 1;
                break;
            }
        }
        return ret;
    }
};
