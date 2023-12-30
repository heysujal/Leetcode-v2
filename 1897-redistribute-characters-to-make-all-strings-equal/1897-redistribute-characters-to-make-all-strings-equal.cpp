class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> arr(26, 0);
        for(auto word : words){
            for(auto ch : word){
                arr[ch-'a']++;
            }
        }
        for(auto x : arr){
            if(x % n != 0){
                return false;
            }
        }
        return true;
    }
};