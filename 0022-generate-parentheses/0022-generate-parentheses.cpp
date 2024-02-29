class Solution {
public:

    bool isValid(string &s){
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(st.top() == '('){
                    st.pop();
                }
            }
        }
        return st.empty();
    }
    void helper(int i, int n, string temp, vector<string> &ans){
        if(i == 2*n){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            return;
        }
        // push '('
        temp += "(";
        helper(i+1, n, temp, ans);
        temp.pop_back();
        temp += ")";
        helper(i+1, n, temp, ans);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, n, "", ans);
        return ans;
    }
};