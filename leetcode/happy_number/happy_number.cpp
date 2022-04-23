class Solution {
public:
    bool isHappy(int n) {
        long long sum = 0;
        vector<int> v;
        while (true) {
            sum += (n % 10) * (n % 10);
            n /= 10;
            if (n == 0) {
                if (sum == 1) {
                    return true;
                }
                for (int i = 0; i < v.size(); i++) {
                    if (v[i] == sum) {
                        return false;
                    }
                }
                v.push_back(sum);
                n = sum;
                sum = 0;
            }
        }
        return false;
    }
};
