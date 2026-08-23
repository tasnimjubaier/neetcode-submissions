class Solution {
public:
    int maxProduct(vector<int>& v) {
        int i, j, n = v.size();
        int ans = -1000000;
        for(i = 0; i < n; i++) {
            int now = 1;
            for(j = i; j < n; j++) {
                now *= v[j];
                ans = max(now, ans);
            }
        }
        return ans;
    }
};
