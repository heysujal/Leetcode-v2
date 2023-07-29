class Solution {
public:
    vector<vector<double>> dp;
    double eatSoup(int A, int B){
        if(A <= 0 and B > 0)
            return 1;
        if(A<=0 and B<=0)
            return 0.5;
        if(A>0 and B<=0)
            return 0.0;
        if(dp[A][B] != -1.0)
            return dp[A][B];
        return dp[A][B] = 0.25*(eatSoup(A-100,B)
                    +eatSoup(A-75,B-25)
                    +eatSoup(A-50,B-50)
                    +eatSoup(A-25,B-75));
    }
    double soupServings(int n) {
        if(n>=4801)
            return 1.0;
        dp.resize(n+1, vector<double>(n+1,-1.0));
        return eatSoup(n,n);
    }
};