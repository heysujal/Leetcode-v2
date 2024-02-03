class Solution {
public:
    int n;
    int helperMemo(int i, vector<int> &arr, int k, vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int len = 0;
        int ans = INT_MIN;
        int sum = INT_MIN;
        int maxi = INT_MIN;

        for(int j = i; j<min(n, i+k); j++){ // or (j < i + k and j < n)
            len++;
            maxi = max(maxi, arr[j]);
            sum = (len * maxi) + helperMemo(j+1, arr, k, dp);
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }

    int helperTab(vector<int> &arr, int k){
        vector<int> dp(n+1, 0);
        dp[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            int len = 0;
            int maxi = INT_MIN;
            int sum = INT_MIN;
            int ans = INT_MIN;
            for(int j = i; j<min(n, i+k); j++){ // or (j < i + k and j < n)
                len++;
                maxi = max(maxi, arr[j]);
                sum = (len * maxi) + dp[j+1];
                ans = max(ans, sum);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        // vector<int> dp(n, -1);
        // return helperMemo(0, arr, k, dp);
        return helperTab(arr, k);
    }
};