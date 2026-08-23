class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        map<string, int> m;
        for(auto u : d) m[u] = 1;
        int n = s.size(), i, j;
        vector<int> dp(n+1, 0);
        dp[n] = 1;

        for(i = n-1; i >= 0; i--) {
            string cur = "";
            int now = 0;
            for(j = i; j <= n-1; j++) {
                cur += s[j];
                if(m.find(cur) != m.end()) 
                    now = max(now, dp[j + 1]);
            }
            dp[i] = now;
        }

        return dp[0];
    }
};
