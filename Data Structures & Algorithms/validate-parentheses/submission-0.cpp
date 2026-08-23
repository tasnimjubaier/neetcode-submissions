class Solution {
public:
    bool notsame(char a, char b) {
        if(b == ')') return a != '(';
        if(b == ']') return a != '[';
        if(b == '}') return a != '{';
    }
    bool isValid(string s) {
        stack<char> S;
        for(auto u : s) {
            if(u == ')' || u == '}' || u == ']') {
                if(S.empty()) return false;
                auto t = S.top(); S.pop();
                if(notsame(t, u)) return false;
            }
            else {
                S.push(u);
            }
        }
        return S.empty();
    }
};
