class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        using vi = vector<int>;
        int n = v.size();
        map<int, int> m;
        vi ans;
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j < n and j - i < k)
                m[v[j]]++, j++;
            if(j - i < k) break;
            if(i) {
                m[v[i-1]]--;
                if(m[v[i-1]] == 0) m.erase(v[i-1]);
            }
            auto pt = m.end(); pt--;
            ans.push_back(pt->first);
        }
        return ans;
    }
};
