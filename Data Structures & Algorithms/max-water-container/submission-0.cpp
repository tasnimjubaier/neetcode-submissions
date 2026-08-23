class Solution {
public:
    int maxArea(vector<int>& v) {
        int ans = 0;
        int i, j, n = v.size(); 
        
        for(i = 1; i <= 1000; i++) {
            int first = -1, second = -1;
            for(j = 0; j < n; j++) {
                if(v[j] >= i) {
                    if(first == -1) first = j;
                    second = j;
                }
            }
            if(first == second) break;

            int now = 0;

            for(j = first + 1; j < second; j++) {
                now += max(i - v[j], 0);
            }
            now = 0;
            now += i * (second - first);

            ans = max(ans, now);
            // cout << i << "  " << now << endl; 
        }

        return ans;
    }
};
