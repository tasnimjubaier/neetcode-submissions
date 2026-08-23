class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            int j = upper_bound(a.begin() + i, a.end(), t - a[i]) - a.begin();
            j--;
            if(j <= i) break;
            if(a[i] + a[j] == t) 
                return vector<int>{i+1, j+1};
        }
    }
};
