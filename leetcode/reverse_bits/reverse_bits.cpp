class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 1;
        uint32_t ret = 0;
        int exp = 31;
        while (n > 0) {
            bool isLsbTrue = mask & n;
            ret += isLsbTrue * (uint32_t)pow(2.0, exp--);
            n = n / 2;
        }
        
        return ret;
    }
};
