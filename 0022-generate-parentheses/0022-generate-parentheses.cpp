class Solution {
public:
    bool isValid(string &s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];         
            if(ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
            else{
                //closing bracket
                if(!st.empty()){
                    char top = st.top();
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || 
                       (ch == ']' &&  top == '['))
                        st.pop();                        
                    else
                        return false;
                } 
                else
                    return false;
            }
        }         
        return st.empty();
    }

    void solve(int idx, string &temp, int n, vector<string> &ans){
        if(idx == 2*n){
            if(isValid(temp))
                ans.push_back(temp);
            return;
        }
        // pick '('
        temp.push_back('(');
        solve(idx+1, temp, n, ans);
        temp.pop_back();
        
        // pick ')'
        temp.push_back(')');
        solve(idx+1, temp, n, ans);
        temp.pop_back();    
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        solve(0,temp,n,ans);
        return ans;
    }
};