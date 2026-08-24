class Solution {
public:
    int minTime(int n, vector<vector<int>>& e, vector<bool>& h) {
        vector<vector<int>> g(n);
        for(auto u : e) {
            g[u[0]].push_back(u[1]);
            g[u[1]].push_back(u[0]);
        }
        

        function<int(int, int)> dfs = [&](int u, int p) -> int {
            int ans = 0;
            for(auto v : g[u]) if(v != p) {
                int rans = dfs(v, u);
                if(rans) ans += rans + 2;
                else if(h[v]) ans += 2;
            }
            return ans;
        };
        int ans = dfs(0, -1);
        return ans;
    }
};