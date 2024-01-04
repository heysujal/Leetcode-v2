class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for(auto &x : nums)
            count[x]++;
        int j = 0;
        for(int i = 0; i < 3; i++){
            int freq = count[i];
            while(freq--){
                nums[j++] = i;
            }
        }
        
    }
};