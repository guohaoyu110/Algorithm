class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
       // not necessary 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //mystack1.push(x);
        queue<int>tempq;
        while(!q.empty()){
            tempq.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!tempq.empty()){
            q.push(tempq.front());
            tempq.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */