class Solution {
public:
    int search(vector<int>& a, int t) {
        int idx;
        int n = a.size();
        {
            int lo = 0, hi = n-1;
            while(lo != hi) {
                int mid = hi - (hi - lo) / 2;
                if(a[mid] >= a[0])
                    lo = mid;
                else
                    hi = mid - 1;
            }
            idx = lo;
        }
        // cout << idx << endl;

        if(t >= a[0]) {
            int id = lower_bound(a.begin(), a.begin() + idx + 1, t) - a.begin();
            if(id < n and a[id] == t) 
                return id;
            return -1;
        }
        else {
            int id = lower_bound(a.begin() + idx + 1, a.end(), t) - a.begin();
            // cout << id << endl;
            if(id < n and a[id] == t) 
                return id;
            return -1;
        }
    }
};
