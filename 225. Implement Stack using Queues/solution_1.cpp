class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int top = q1.front();
        q1.pop();
        while (!q1.empty()) {
            q2.push(top);
            top = q1.front();
            q1.pop();
        }
        swap(q1, q2);
        return top;
    }
    
    /** Get the top element. */
    int top() {
        int top;
        while (!q1.empty()) {
            top = q1.front();
            q1.pop();
            q2.push(top);
        }
        swap(q1, q2);
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
//two queue solution

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */