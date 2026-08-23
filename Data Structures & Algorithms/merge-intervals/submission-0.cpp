class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iv) {
        vector<array<int, 3>> v;
        for(auto u : iv) {
            v.push_back({u[0], 0, u[1]});
            v.push_back({u[1], 1, u[0]});
        }
        sort(v.begin(), v.end());

        vector<vector<int>> ans; 
        int isinint = 0, endpoint = -1, startpoint = -1;

        for(auto x : v) {
            auto [u, s, d] = x;
            if(s == 0) {
                isinint = 1; 
                endpoint = max(endpoint, d);
                if(startpoint == -1) startpoint = u;
            }
            else {
                if(endpoint == u) {
                    ans.push_back({startpoint, endpoint});

                    isinint = 0;
                    endpoint = -1;
                    startpoint = -1;
                }
            }
        }

        return ans;
    }
};
