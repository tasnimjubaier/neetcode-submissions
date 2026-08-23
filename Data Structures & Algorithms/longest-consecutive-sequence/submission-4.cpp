class Solution {
public:
    unordered_map<int, int> m, vis; 

    int dfs(int u) {
        int ret = 1;
        vis[u] = 1;
        if(m.find(u - 1) != m.end() and vis[u - 1] == 0) 
            ret += dfs(u-1);
        if(m.find(u + 1) != m.end() and vis[u + 1] == 0) 
            ret += dfs(u+1);
        
        return ret;
    }

    int longestConsecutive(vector<int>& v) {
        int ans = 0;
        int i, n = v.size();
        m.clear(), vis.clear();
        for(auto u : v) m[u] = 1;
        // sort(v.begin(), v.end());
        // for(auto u : v) cout << u << " ";
        // cout << endl;

        for(auto u : m) {
            auto node = u.first;
            // cout << u.first << "    " << u.second << endl;
            if(vis[node] == 0) {
                int now = dfs(node);
                ans = max(ans, now);
                // cout << node << "  " << now << endl;
            }
        }

        return ans;
    }
};
