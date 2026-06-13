class MinStack {
    stack<int> vals, mins;
public:
    void push(int value) {
        vals.push(value);
        mins.push(mins.empty() ? value : min(mins.top(), value));
    }
    
    void pop() {
        vals.pop();
        mins.pop();
    }
    
    int top() {
        return vals.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
