class Solution {
public:
    // Approach
    // Follow logic of valid parenthesis but store idx instead
    // after that add all the elements of stack in a set
    // elements in set are indices to be ignored

    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        unordered_set<int> toBeRemoved;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    toBeRemoved.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            toBeRemoved.insert(st.top());
            st.pop();
        }
        
        string ans = "";
        for(int i = 0; i < n; i++){
            if(toBeRemoved.find(i) == toBeRemoved.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};