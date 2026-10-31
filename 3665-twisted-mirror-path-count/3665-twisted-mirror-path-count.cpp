class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<array<long long, 2>>> dp(
            m, vector<array<long long, 2>>(n, {0, 0})
        );

        dp[0][0][0] = 1; // start; (0,0) is empty, so it branches both ways below

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 2; d++) {
                    long long ways = dp[i][j][d];
                    if (ways == 0) continue;

                    for (int od = 0; od < 2; od++) {
                        // Mirror: forced to leave in the flipped direction
                        if (grid[i][j] == 1 && od != 1 - d) continue;

                        int ni = i + (od == 1);
                        int nj = j + (od == 0);
                        if (ni >= m || nj >= n) continue;

                        dp[ni][nj][od] = (dp[ni][nj][od] + ways) % MOD;
                    }
                }
            }
        }

        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    }
};