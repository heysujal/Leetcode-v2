class MinStack {
public:
    stack<int> main, aux;
    MinStack() {

    }
    
    void push(int val) {
        main.push(val);
        if(aux.empty() or val <= aux.top()){
            aux.push(val);
        }
    }
    
    void pop() {
        int val = main.top();
        main.pop();
        if(val == aux.top()){
            aux.pop();
        }
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return aux.top();
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