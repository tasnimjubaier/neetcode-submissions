class Solution {
public:
    using pii = pair<int, int>;
    int trap(vector<int>& v) {
        int n = v.size();
        stack<pii> S;
        int ans = 0;
        for(int i = 0; i < v.size(); i++) {
            int base = 0;
            while(!S.empty()) {
                auto [h, id] = S.top();
                if(h <= v[i]) {
                    ans += (h - base) * (i - id - 1);
                    S.pop();
                    base = h;
                }
                else {
                    ans += (v[i] - base) * (i - id - 1);
                    break;
                }
            }
            S.push({v[i], i});
        }
        return ans;
    }
};
