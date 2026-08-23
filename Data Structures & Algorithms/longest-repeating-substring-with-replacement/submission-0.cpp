class Solution {
public:
    int characterReplacement(string s, int T) {
        int ans = 0, i, j, n = s.size();

        for(int k = 0; k < 26; k++) {
            i = 0, j = -1;
            int cnt = 0;
            
            while(i < n) {
                while((j+1) < n and (cnt + (((s[j+1] - 'A') != k))) <= T) {
                    j++;
                    cnt += ((s[j] - 'A') != k);
                }

                ans = max(ans, j - i + 1);
                // cout << cnt << "  " << j - i  + 1 << " " << k << endl;
                cnt -= ((s[i] - 'A') != k);
                i++;
                j = max(j, i-1);
            }
        }

        return ans;
    }
};