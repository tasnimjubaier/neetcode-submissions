class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size(), i, j;
        vector<bool> ok(n, 0);
        ok[n-1] = 1;
        int lastok = n-1;

        for(i = n-2; i >= 0; i--) {
            int x = v[i];
            int d = i + x; 

            if(d >= lastok) ok[i] = 1, lastok = i;
        } 
        
        return ok[0];
    }
};
