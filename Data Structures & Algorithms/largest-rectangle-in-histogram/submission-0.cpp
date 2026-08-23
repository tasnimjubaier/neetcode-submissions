class Solution {
public:
    
    vector<vector<int>> tree;
    
    void build(vector<int>& a){
        int n = a.size();
        tree.assign(n + 1, vector<int>(20, 0));
        for(int i = 0; i < n; i++)
            tree[i][0] = a[i];
        for(int k = 1; k < 20; k++) {
            int d = 1 << k;
            if(d > n) break;
            for(int i = 0; i < n; i++) {
                if(i + d > n) break;
                tree[i][k] = min(tree[i][k-1], tree[i + (d >> 1)][k-1]);
            }
        }
    }
    int query(int l, int r) {
        int res = 100000000;
        for(int k = 20, d = (1 << k); k >= 0; k--, d >>= 1) {
            if(l + d > r + 1) continue;
            res = min(res, tree[l][k]);
            l += d;
        }
        return res;
    }


    int largestRectangleArea(vector<int>& v) {
        build(v);
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int l = i, r = i;
            {
                int lo = 0, hi = i;
                while(lo != hi) {
                    int mid = (lo + hi) / 2;
                    if(query(mid, i) >= v[i])
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                l = lo;
            }
            {
                int lo = i, hi = n-1;
                while(lo != hi) {
                    int mid = hi - (hi - lo) / 2;
                    if(query(i, mid) >= v[i]) 
                        lo = mid;
                    else 
                        hi = mid - 1;
                }
                r = lo;
            }
            ans = max(ans, (r - l + 1) * v[i]);
        }
        return ans;
    }
};
