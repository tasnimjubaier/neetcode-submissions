class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int i, n = v.size();
        vector<int> p(n+2, 0), s(n+2, 0), ans;
        p[0] = 1;
        for(i = 0; i < n; i++) p[i+1] = p[i] * v[i];
        s[n+1] = 1;
        for(i = n-1; i >= 0; i--) s[i+1] = s[i+2] * v[i];

        for(i = 1; i <= n; i++) ans.push_back(p[i-1] * s[i+1]);
        return ans;
    }
};
