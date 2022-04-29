class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        while (n > 0) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
            if (n == 1) {
                return true;
            }
        }
        int count = 0;
        long long temp = n;
        while (temp < 0 && count < 31) {
            temp *= 3;
            if (temp < -pow(2, -31)) {
                return false;
            }
            count++;
            if (temp == -1) {
                return true;
            }
        }
        return false;
    }
};

