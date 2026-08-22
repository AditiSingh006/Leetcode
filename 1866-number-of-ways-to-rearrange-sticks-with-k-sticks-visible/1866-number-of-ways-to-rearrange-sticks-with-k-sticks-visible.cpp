class Solution {
public:
    int rearrangeSticks(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

        dp[1][1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] += (i - 1) * dp[i - 1][j];

                dp[i][j] %= MOD;
            }
        }

        return dp[n][k];
    }
};