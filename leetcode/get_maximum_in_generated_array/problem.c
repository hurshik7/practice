
int dp[101];

int getMaximumGenerated(int n){
    dp[0] = 0;
    dp[1] = 1;
    int max = -1;
    for (size_t i = 0; i < 101; i++) {
        if (2 <= i * 2 && i * 2 <= n) {
            dp[2 * i] = dp[i];
        } 
        if (2 <= (2 * i + 1) && (2 * i + 1) <= n) {
            dp[2 * i + 1] = dp[i] + dp[i + 1];
        }
    }
    for (size_t i = 0; i < n + 1; i++) {
        max = max < dp[i] ? dp[i] : max;
    }
    
    return max;
}
