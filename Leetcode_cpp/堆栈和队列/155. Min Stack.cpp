class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        // not necessary
    }
    
    void push(int x) {
        stk.push(x);
        if(minStk.empty()||x<=minStk.top()){
            minStk.push(x);
        }
    }
    
    void pop() {
        int top = stk.top();
        stk.pop();
        if (top == minStk.top())
            minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        //return stk.pop();
        return minStk.top();
    }
private:
    stack<int> stk, minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */