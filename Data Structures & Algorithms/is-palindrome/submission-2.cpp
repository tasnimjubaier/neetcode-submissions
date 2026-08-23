class Solution {
public:
    bool isPalindrome(string s) {
        string r = "";
        for(auto u : s) {
            if(u >= 'a' and u <= 'z') r += u;
            if(u >= 'A' and u <= 'Z') r += (u - 'A' + 'a');
            if(u >= '0' and u <= '9') r += u;
        }
        s = r;
        int n = s.size(), i;
        for(i = 0; i <= n/2; i++){
            if(s[i] != s[n-1-i]) 
                return 0;
        }
        return 1;
    }
};
