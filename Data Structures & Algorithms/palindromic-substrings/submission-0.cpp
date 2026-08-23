class Solution {
public:
    int countSubstrings(string s) {
        string t = "#";
        for(auto u : s) t += u, t += '#';
        int cnt = 0;
        int i, j, k;
        for(i = 1; i < t.size() - 1; i++) {
            for(j = i, k = i; j < t.size(), k >= 0; j++, k--) {
                if(t[j] == '#') continue;
                if(t[j] != t[k]) break;
                cnt++;
            }
        }

        return cnt;
    }
};
