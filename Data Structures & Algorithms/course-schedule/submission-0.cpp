class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        int finished = 0, i, j;
        vector<int> deg(n, 0);
        vector<vector<int>> g(n, vector<int>{});
        for(auto u : p) {
            deg[u[0]]++;
            g[u[1]].push_back(u[0]);
        }
        queue<int> q;
        for(i = 0; i < n; i++) if(deg[i] == 0) q.push(i);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            finished++;
            for(auto v : g[u]) {
                deg[v]--;
                if(deg[v] == 0) q.push(v);
            }
        }

        return finished == n;
    }
};
