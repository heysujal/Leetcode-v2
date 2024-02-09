class MinStack {
public:
    vector<pair<int, int>> v;

    MinStack() {

    }
    
    void push(int val) {
        if(v.empty()){
            v.push_back({val, val});
        }
        // what mini to push with val?
        else{
            int mini;
            if(v.back().second <= val){
                mini = v.back().second;
            } 
            else{
                mini = val;
            }
            v.push_back({val, mini});
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
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