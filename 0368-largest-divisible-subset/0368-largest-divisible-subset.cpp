class Solution {
public:
    // using special tabulation
    vector<int> printLIS(vector<int> &nums){
        int n = nums.size();
        // important
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int ans = -1;
        int lastInd = -1;
    
        for(int i = 0 ; i <= n-1 ; i++){
            hash[i] = i;
            for(int prev_ind = 0; prev_ind <= i-1 ; prev_ind++){

                if(nums[i] % nums[prev_ind] == 0 && ( 1 + dp[prev_ind] > dp[i])){
                    dp[i] =  1 + dp[prev_ind];
                    hash[i] = prev_ind;
                }

            }
              if(dp[i] > ans){
                ans = dp[i];
                lastInd = i;
            }
        }   
         
       
        vector<int> temp;
        temp.push_back(nums[lastInd]);
        
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        // reverse(temp.begin(), temp.end());
        for(auto x : temp)
            cout<<x<<" "<<endl;

        return temp;
            
    }
     
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return printLIS(nums);
    }   
};