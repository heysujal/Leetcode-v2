class Solution {
public:
    bool hasCommon(string &p, string &q){
        vector<int> v(26, 0);
        for(auto &c : p){
            v[c-'a']++;
            // also to handle ["aa", "bb"] test case
            if(v[c-'a'] > 1)
                return true;
        }
        for(auto &c : q){
            if(v[c-'a'] > 0){ // this means c is present in a
                return true;
            }
        }
        return false;
    }
    int helperMemo(int i, string temp, vector<string> &arr,
    unordered_map<string, int> &mp){
        if(i >= arr.size()){
            return temp.size();
        }
        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }
        // if temp and arr[i] don't have anything in common
        // then we can include or exclude
        int include = 0;
        int exclude = 0;
        if(!hasCommon(arr[i], temp)){
            // exclude
            exclude = helperMemo(i+1, temp, arr, mp);
            // include
            include = helperMemo(i+1, temp+arr[i], arr, mp);
        }
        else{
            exclude = helperMemo(i+1, temp, arr, mp);
        }
        return mp[temp] = max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        unordered_map<string, int> mp;
        return helperMemo(0, temp, arr, mp);
    }
};