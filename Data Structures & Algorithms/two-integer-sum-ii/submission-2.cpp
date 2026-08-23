class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size();
        for(int i = 0; i < n; i++) {
            int j = upper_bound(a.begin(), a.end(), t - a[i]) - a.begin();
            j--;
            if(j <= i or j < 0) break;
            if(a[i] + a[j] == t) 
                return vector<int>{i+1, j+1};
        }
    }
};
