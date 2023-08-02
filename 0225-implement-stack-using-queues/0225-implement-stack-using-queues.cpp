class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        queue<int> temp;
        int size = q1.size()-1;
        while(size--){
            int f = q1.front();
            temp.push(f);
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        q1 = temp;
        return ans;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */