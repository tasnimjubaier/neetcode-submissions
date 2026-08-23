class Solution {
public:
    vector<int> ans;
    int done = 0;
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};

    bool val(int x, int y, int n, int m, vector<vector<int>>& vis) {
        if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y])
            return 0;
        return 1;
    }

    void dfs(vector<vector<int>>& v, vector<vector<int>>& vis, int px, int py, int n, int m, int st) {
        if(done == n*m) return ;

        int xx = px + x[st];
        int yy = py + y[st];
        if(!val(xx, yy, n, m, vis)) {
            st = (st + 1) % 4;
            return dfs(v, vis, px, py, n, m, st);
        }

        vis[xx][yy] = 1;
        done++;
        ans.push_back(v[xx][yy]);

        dfs(v, vis, xx, yy, n, m, st);
    }

    vector<int> spiralOrder(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[0][0] = 1; done = 1;
        ans.push_back(v[0][0]);
        dfs(v, vis, 0, 0, n, m, 0);
        return ans;
    }
};