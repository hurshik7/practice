class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int init = prices[0];
        int maxProfit = -1;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > init) {
                if (maxProfit < prices[i] - init) {
                    maxProfit = prices[i] - init;
                }
            }
            else if (prices[i] < init) {
                init = prices[i];
            }
        }
        if (maxProfit < 0) {
            return 0;
        }
        return maxProfit;
    }
};
