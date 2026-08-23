class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size(), i;
        vector<int> s(n+1, 0);
        for(i = 0; i < n; i++) s[i+1] = s[i] + v[i];

        int ans = -100000000, cmin = 0;
        for(i = 1; i <= n; i++) {
            ans = max(ans, s[i] - cmin);
            cmin = min(cmin, s[i]);
        }
        
        return ans;
    }
};
