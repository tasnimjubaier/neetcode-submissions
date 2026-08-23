class Solution {
public:
    int C(char c) {
        if(c >= 'A' and c <= 'Z') return c - 'A';
        else return c - 'a' + 26;
    }
    string minWindow(string s, string t) {
        vector<int> v[52];
        int i, j, n = s.size(), m = t.size();
        vector<int> cn(52, 0); for(auto u : t) cn[C(u)]++;

        for(i = 0; i < 52; i++) {
            int las = 0;
            for(j = 0; j < n; j++) {
                if(C(s[j]) == i) las++;
                v[i].push_back(las);
            }
        }
        
        int inpos, len = 1000000;

        for(i = 0; i < n; i++) {
            int l = i;
            for(j = 0; j < 52; j++) {
                if(cn[j] == 0) continue;
                int look = (i == 0) ? cn[j] : cn[j] + v[j][i-1];
                auto it = upper_bound(v[j].begin(), v[j].end(), look - 1);
                
                if(it == v[j].end()) { l = 1000000000; break;}
                
                int pos = it - v[j].begin();
                
                l = max(l, pos);
            }

            if(len > l - i + 1) len = l - i + 1, inpos = i;
        }
        
        if(len == 1000000) return "";
        string g = "";
        for(i = inpos; i < inpos + len; i++) g += s[i];
        return g;
    }
};