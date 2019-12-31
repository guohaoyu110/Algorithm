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
        //这里的&符号特别重要，不是只复制数值，而是每个地址都要复制进去！
        while(a.size()){//&符号是取a的地址
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
        stk.empty();//这一步是可做可不做的
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