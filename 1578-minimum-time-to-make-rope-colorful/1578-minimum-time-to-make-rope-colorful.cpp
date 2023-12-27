class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        int n = colors.size();
        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                int start = i;
                int sum = neededTime[i-1];
                int costly = neededTime[i-1];
                while((start < n) and (colors[start] == colors[start-1])){
                   sum += neededTime[start];
                   costly = max(costly, neededTime[start]);
                   start++;
                }
                i = start-1;
                cost += (sum - costly);
            }
        }
        return cost;
    }
};