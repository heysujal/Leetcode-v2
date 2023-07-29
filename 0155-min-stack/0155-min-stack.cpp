class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        // equality symbol is because
        // if you push same element twice in mainStack 
        // them you have to push it twice in the minStack too. 
        // because u are checking for equality when popping element.
        if(minStack.empty() or (val <= minStack.top()))
            minStack.push(val);
    }
    
    void pop() {
        int val = mainStack.top();
        mainStack.pop(); 
        if(!minStack.empty() and (val == minStack.top()))
            minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */