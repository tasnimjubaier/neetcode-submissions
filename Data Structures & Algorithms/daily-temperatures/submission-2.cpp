class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 0);
        using pii = pair<int, int>;
        stack<pii> S;
        for(int i = n-1; i >= 0; i--) {
            while(!S.empty()) {
                auto tp = S.top();
                if(tp.first <= v[i]) S.pop();
                else {
                    ans[i] = tp.second - i;
                    break;
                }
            }
            S.push({v[i], i});
        }
        return ans;
    }
};
