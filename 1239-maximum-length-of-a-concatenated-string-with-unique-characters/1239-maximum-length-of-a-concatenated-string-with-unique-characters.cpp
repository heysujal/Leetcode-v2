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
            v[c-'a']++;
            if(v[c-'a'] > 1){
                return true;
            }
        }
        return false;
    }
    int helper(int i, string temp, vector<string> &arr){
        if(i >= arr.size()){
            return temp.size();
        }
        // if temp and arr[i] don't have anything in common
        // then we can include or exclude
        int include = 0;
        int exclude = 0;
        if(!hasCommon(arr[i], temp)){
            // exclude
            exclude = helper(i+1, temp, arr);
            // include
            include = helper(i+1, temp+arr[i], arr);
        }
        else{
            exclude = helper(i+1, temp, arr);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        string temp = "";
        return helper(0, temp, arr);
    }
};