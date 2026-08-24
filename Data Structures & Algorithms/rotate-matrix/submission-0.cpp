class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        
        int n = m.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < n/2 or j < n/2) continue;
                int x = m[i][j];
                m[i][j] = m[n - j - 1][i];
                m[n - j - 1][i] = m[n - i - 1][n - j - 1];
                m[n - i - 1][n - j - 1] = m[j][n - i - 1];
                m[j][n - i - 1] = x;
            }
        }
        if(n&1) {
            int j = n/2;
            int cnt = 3;
            while(cnt--) for(int i = 0; i < n/2; i++) {

                int x = m[i][j];
                m[i][j] = m[n - j - 1][i];
                m[n - j - 1][i] = m[n - i - 1][n - j - 1];
                m[n - i - 1][n - j - 1] = m[j][n - i - 1];
                m[j][n - i - 1] = x;
            }
        }
    }
};
