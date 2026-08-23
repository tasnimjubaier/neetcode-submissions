class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int m = a.size();
        int n = a[0].size();
        int id1;
        {
            int lo = 0, hi = m-1;
            if(a[0][0] > t) 
                return false;
            while(lo != hi) {
                int mid = hi - (hi - lo) / 2;
                if(a[mid][0] <= t) 
                    lo = mid;
                else
                    hi = mid - 1;
            }
            id1 = lo;
        }

        int id2 = lower_bound(a[id1].begin(), a[id1].end(), t) - a[id1].begin();
        if(id2 == n or a[id1][id2] != t) 
            return false;
        return true;
    }
};
