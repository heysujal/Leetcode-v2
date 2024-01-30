class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> st;
        for(auto &s : tokens){
            if(s == "+" or s == "-" or s == "/" or s == "*"){
                if(st.size() < 2){
                    return -1e9;
                }
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if(s == "+"){
                    st.push(op1 + op2);
                }
                else if(s == "/"){
                    st.push(op2/op1);
                }
                else if(s == "-"){
                    st.push(op2 - op1);
                }
                else{
                    st.push(op1 * op2);
                }
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};