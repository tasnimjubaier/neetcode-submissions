class Solution {
public:
    bool checkInclusion(string sa, string sb) {
        int n = sa.size();
        int m = sb.size();
        using vii = vector<vector<int>>;
        using vi = vector<int>;
        vi va(26, 0), vb(26, 0);
        for(auto c : sa) {
            va[c - 'a']++;
        }
        int jl = 0, jr = 0;
        for(int i = 0; i < m; i++) {
            {
                while(jr < m and jr < i + n)
                    vb[sb[jr] - 'a']++, jr++;
                while(jl < i)
                    vb[sb[jl] - 'a']--, jl++;

                if(jr == i + n and va == vb)
                    return true;
            }
        }
        return false;
    }
};
