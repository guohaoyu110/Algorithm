class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk, cache;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    
    void copy(stack<int>&a,stack<int>&b){
        while(a.size()){
            b.push(a.top());
            a.pop();
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //弹出元素和堆栈是反过来的
        copy(stk,cache);
        int number = cache.top();
        cache.pop();
        //stk.empty();
        copy(cache,stk);
        return number;
    }
    /** Get the front element. */
    int peek() {
        //return stk.top();
        copy(stk,cache);
        int res = cache.top();
        copy(cache,stk);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */