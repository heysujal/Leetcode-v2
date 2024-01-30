class Solution {
public:
    // using given input vector as stack
    int evalRPN(vector<string>& tokens) {
        int top = 0;
        for(auto &s : tokens){
            if(s == "+" or s == "-" or s == "/" or s == "*"){
                int op1 = stoi(tokens[--top]);
                int op2 = stoi(tokens[--top]);
                int res = 0;
                if(s == "+"){
                    res = op1 + op2;
                }
                else if(s == "/"){
                    res = op2 / op1;
                }
                else if(s == "-"){
                    res = op2 - op1;
                }
                else{
                    res = op1 * op2;
                }
                tokens[top++] = to_string(res);
            }
            else{
                tokens[top++] = s;
            }
        }
        return stoi(tokens[0]);
    }
};