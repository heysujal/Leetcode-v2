class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prevMax = 0;
        int time = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 and colors[i] != colors[i-1])
                prevMax = 0;// if diff colors then no need to add time
            // keeping track of costlyBallon till now in prevMax
            time += min(prevMax, neededTime[i]); 
            prevMax = max(prevMax, neededTime[i]);
        }   
        return time;
    }
};