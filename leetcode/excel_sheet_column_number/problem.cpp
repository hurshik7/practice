class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        long long digit = 1;
        for (int i = columnTitle.length() - 1; i >= 0; --i) {
            sum += digit * (columnTitle[i] - 'A' + 1);
            digit *= 26;
        }
        return sum;
    }
};
