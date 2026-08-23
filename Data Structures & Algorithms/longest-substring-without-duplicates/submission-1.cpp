class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> cnt;
        int i, n = s.size();
        int j = -1;
        int ans = 0;
        for(i = 0; i < n; i++) {
            if(j < i) {
                j = i;
                cnt[s[i]]++;
            }
            while((j+1) < n and 
                    cnt[s[j+1]] == 0){
                        j++;
                        cnt[s[j]]++;
                    }
            ans = max(ans, j - i + 1);
            cnt[s[i]]--;
        }
        return ans;
    }
};
