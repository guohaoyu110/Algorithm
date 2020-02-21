class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        // not necessary
        // 惯例，这道题目是用两个stack去实现一个queue
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!Mystack.empty()){
            s.push(Mystack.top());
            Mystack.pop();
        }
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //stack<int> Mystack;
        while(!s.empty()){
            Mystack.push(s.top());
            s.pop();
        }
        int h = Mystack.top();
        Mystack.pop();
        return h;
    }
    
    /** Get the front element. */
    int peek() {
        // while(s.size()!=1&&s.size()!=0){
        //     s.pop();
        // }
        // return s
        // 这个要用两个stack来实现这个功能
        //stack<int>Mystack;
        while(!s.empty()){
            Mystack.push(s.top());
            s.pop();
        }
        return Mystack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty()&&Mystack.empty();
    }
private: 
    stack<int> s,Mystack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */