class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="")
            return 0;
        // remove valid parts
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n ; i++){
            if(s[i] == '(')
                st.push('(');
            else{
                if(st.empty())
                    st.push(s[i]);
                else if(st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        // only invalid parts
        int open = 0;
        int close = 0;
        while(!st.empty()){
            if(st.top() == '(')
                open++;
            else
                close++;
            st.pop();
        }
        return open + close;
    }
};