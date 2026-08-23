class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int> S;
        for(auto s : v) {
            if(s == "+") {
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                a += b;
                S.push(a);
            }
            else if(s == "-") {
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                a -= b;
                S.push(a);
            }
            else if(s == "*") {
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                a *= b;
                S.push(a);
            }
            else if(s == "/") {
                int b = S.top(); S.pop();
                int a = S.top(); S.pop();
                a /= b;
                S.push(a);
            }
            else {
                int a = stoi(s);
                S.push(a);
            }
        }
        return S.top();
    }
};
