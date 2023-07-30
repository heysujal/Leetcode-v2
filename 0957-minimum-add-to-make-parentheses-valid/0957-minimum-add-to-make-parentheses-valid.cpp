class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="")
            return 0;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if(ch == '(')
                st.push(ch);
            else{
                // ch is a closing parenthesis
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(ch);
            }            
        }
        int open = 0;
        int close = 0;
        while(!st.empty()){
            if(st.top()=='(')
                open++;
            else
                close++;    
            st.pop();
        }
        return open + close;
    }
};