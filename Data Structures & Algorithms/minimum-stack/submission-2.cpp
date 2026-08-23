class MinStack {
    map<int, int> m;
    stack<int> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        m[val]++;
    }
    
    void pop() {
        int it = s.top(); s.pop();
        m[it]--;
        if(m[it]==0) m.erase(it);
    }
    
    int top() {
        int it = s.top(); 
        return it;
    }
    
    int getMin() {
        auto it = m.begin(); 
        return it->first;
    }
};
