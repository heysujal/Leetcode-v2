class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int m = g.size();
        int j = 0;
        int n = s.size();

        while(i < m and j < n){
            if(s[j] >= g[i]){
                count++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return count;
    }
};