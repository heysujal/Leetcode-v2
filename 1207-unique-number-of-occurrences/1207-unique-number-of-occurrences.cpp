class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, bool> vis;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            if(!vis[arr[i]]){
                vis[arr[i]] = true;
                int count = 1;
                int j = i+1;
                while(j < n){
                    if(arr[j] == arr[i]){
                        count++;
                    }
                    j++;
                }
                if(st.find(count) != st.end()){
                    return false;
                }
                st.insert(count);
            }
        }
        return true;
    }
};