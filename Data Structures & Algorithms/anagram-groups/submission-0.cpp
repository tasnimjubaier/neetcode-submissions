class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> M;
        for(auto u : strs) {
            auto v = u;
            sort(u.begin(), u.end());
            M[u].push_back(v);
        }
        vector<vector<string>> ret; 
        for(auto [s, v] : M) {
            ret.push_back(v);
        }
        
        return ret;
    }
};
