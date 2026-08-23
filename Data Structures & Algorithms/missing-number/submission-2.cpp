class Solution {
public:
    int missingNumber(vector<int>& v) {
        int sum = 0;
        int n = v.size();
        for(auto u : v) {
            sum += u;
        }
        return (n*(n+1))/2 - sum;
    }
};
