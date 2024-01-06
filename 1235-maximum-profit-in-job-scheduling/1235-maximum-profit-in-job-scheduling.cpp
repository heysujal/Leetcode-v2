class Solution {
public:
    int n;

    int getNextGreater(int low, vector<vector<int>> &v, int &currJobEnd){
        int high = n-1;
        int ans = n+1; // <= give this a random value that hits the base case
        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid][0] >= currJobEnd){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int helper(int i, vector<vector<int>> &v, vector<int> &dp){
        if(i>=n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int nextIndex = getNextGreater(i+1, v, v[i][1]);
        int pick = v[i][2] + helper(nextIndex, v, dp);
        int skip = 0 + helper(i+1, v, dp);
        return dp[i] = max(pick, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        vector<int> dp(n, -1);
        //no need of comp, only for learning
        auto comp = [&](auto &v1, auto &v2){
            return v1[0] <= v2[0];
        };
        sort(v.begin(), v.end(), comp);
        return helper(0, v, dp);
    }
};