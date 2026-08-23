class Solution {
public:
    int n, m;
    string a, b;
    int dp[1002][1002];

    int sol(int x, int y) {
        if(x < 0 or y < 0) return 0;
        
        if(dp[x][y] != -1) return dp[x][y];

        if(a[x] == b[y]) return dp[x][y] = 1 + sol(x-1, y-1);

        dp[x][y] = max(sol(x, y-1), sol(x-1, y));

        return dp[x][y];
    }

    int longestCommonSubsequence(string aa, string ba) {
        a = aa, b = ba;
        n = a.size(), m = b.size();
        for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = -1;
        return sol(n-1, m-1);
    }
};
