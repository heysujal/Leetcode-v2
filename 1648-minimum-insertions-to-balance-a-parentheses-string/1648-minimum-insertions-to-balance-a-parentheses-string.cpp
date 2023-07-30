class Solution {
public:
    int minInsertions(string t) {
        int ans=0;
        stack<char> s;
        int n = t.length();
        for(int i=0;i<n;i++){
            char c = t[i];
            if(c=='(')
                s.push('(');
            else{
                if(s.empty()){
                    if(i+1<n && t[i+1]==')')
                        ans++,i++;
                    else
                        ans+=2;
                }
                else{
					s.pop();
                    if(i+1<n && t[i+1]==')') i++;
                    else ans++;					
                }
            }
        }
        
        while(!s.empty()){
            s.pop();
            ans+=2;
        }
        return ans;
    }
};