class Solution {
public:
    bool isUnique(string s){
        vector<int> v(26, 0);
        for(auto &ch : s){
            v[ch-'a']++;
            if(v[ch-'a'] > 1){
                return false;
            }
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        if(n==1){
            return arr[0].size();
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            string s=arr[i];
            for(int j = i+1; j < n; j++){
                string t = s + arr[j];
                if(isUnique(t)){
                    // if unique then update s
                    int k = t.size();
                    ans = max(ans, k);
                    s = t;
                }
                else{
                    // do nothing
                }
            }
        }
        return ans;
    }
};