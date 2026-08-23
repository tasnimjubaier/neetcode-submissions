class Solution {
    string randstr;
    int randstrsize;
    
    void generateRandomString(int l) {
        srand(time(nullptr));
        randstr = "";
        for(int i = 0; i < l; i++) {
            int random = rand() % 256;
            // cout << random;
            randstr += (char)random;
        }
    }
public:
    Solution() {
        randstrsize = 10;
        generateRandomString(randstrsize);
    }
    string encode(vector<string>& strs) {
        string code = "";
        for(auto s : strs) code += s, code += randstr;
        return code;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int n = s.size();
        string cache = "";
        int i = 0;
        while(i < n) {
            string breaker = "";
            for(int j = i; j < i + randstrsize; j++) {
                if(j == n) break;
                breaker += s[j];
            }
            if(breaker == randstr) {
                v.push_back(cache);
                cache = "";
                i = i + randstrsize;
            }
            else {
                cache += s[i];
                i++;
            }
        }
        return v;
    }
};
