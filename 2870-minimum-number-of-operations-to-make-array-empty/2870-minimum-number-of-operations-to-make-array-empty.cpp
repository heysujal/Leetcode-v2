class Solution {
public:

    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ops = 0;
        for(auto &x : nums){
            mp[x]++;
        }
        // idea is to add ceil of num/3
        for(auto &it : mp){
            int freq = it.second;
            if(freq == 1)
                return -1;
            
            ops += ceil((double)freq/3);
        }
        return ops;
    }
};