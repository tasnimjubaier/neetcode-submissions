class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> M;
        for(auto u : nums) M[u]++;
        priority_queue<array<int, 2>> p;
        for(auto [u, v] : M) p.push({v, u});
        vector<int> ans;
        while(k--) {
            auto t = p.top(); p.pop(); ans.push_back(t[1]);
        }
        return ans;
    }
};
