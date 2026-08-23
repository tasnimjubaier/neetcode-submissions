class Solution {
public:
    int search(vector<int>& v, int t) {
        int x = lower_bound(v.begin(), v.end(), t) - v.begin();
        if(x < v.size() and v[x] == t) return x; 
        return -1;
    }
};
