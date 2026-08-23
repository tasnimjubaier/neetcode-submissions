class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& v) {
        map<int, int> m; set<int> s; vector<int> x; 
        for(auto u : v) m[u]++, s.insert(u);
        vector<vector<int>> ans;

        for(auto u : s) x.push_back(u);
        int n = x.size(), i, j;
        for(i = 0; i < n; i++) {
            m[x[i]]--;
            for(j = i; j < n; j++) {
                if(m[x[j]] == 0) continue;
                m[x[j]]--;

                int d = - (x[i] + x[j]);

                if(d >= x[j] and m[d] != 0) 
                    ans.push_back(vector<int>{x[i], x[j], d});
                
                m[x[j]]++;
            }
            m[x[i]]++;
        }

        return ans;
    }
};
