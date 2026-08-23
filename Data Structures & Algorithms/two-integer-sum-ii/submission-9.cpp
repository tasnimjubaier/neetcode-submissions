class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size();
        int j = n-1;
        for(int i = 0; i < n; i++) {
            {
                while(a[i] + a[j] > t) j--;
                if(a[i] + a[j] == t) 
                    return vector<int>{i+1, j+1};
            }
        }
    }
};
