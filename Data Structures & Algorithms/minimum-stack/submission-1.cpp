class MinStack {
public:
    stack<int> st;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st2.empty() || val<=st2.top()){
            st2.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(st.top() == st2.top()){
            st2.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
