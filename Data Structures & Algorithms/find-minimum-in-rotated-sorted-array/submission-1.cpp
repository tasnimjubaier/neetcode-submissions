class Solution {
public:
    int findMin(vector<int>& v) {
       int n = v.size(), i , j;
        if(v[0] < v[n-1]) return v[0];
        int l = 0, r = n-1;
        while(l < r - 1) {
            int mid = (l + r) / 2;
            if(v[mid] < v[0]) r = mid;
            else l = mid;
        }
        return v[r]; 
    }
};