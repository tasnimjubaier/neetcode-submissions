class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& iv) {
        int cnt = 0;
        int mxd = -1000000;
        sort(iv.begin(), iv.end());

        for(auto u : iv) {
            if(mxd <= u[0]) mxd = u[1];
            else {
                cnt++;
                mxd = min(mxd, u[1]);
            }
            // cout << mxd << endl;
        }
        return cnt; 
    }
};
