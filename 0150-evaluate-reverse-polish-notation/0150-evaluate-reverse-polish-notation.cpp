class Solution {
public:
    bool isOperator(string &s){
        return s=="*" or s=="+" or s=="-" or s=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i = 0; i < tokens.size(); i++){
            if(!isOperator(tokens[i])){
                st.push(tokens[i]);
            }
            else{
                int num2 = stoi(st.top()); st.pop();
                int num1 = stoi(st.top()); st.pop();
                int res = 0;
                if(tokens[i]=="*")
                    res = num1*num2;
                else if(tokens[i] == "+")
                    res = num1+num2;
                else if(tokens[i] == "-")
                    res = num1-num2;
                else
                    res = num1/num2;
                st.push(to_string(res));
            }
        }
        return stoi(st.top());
    }
};