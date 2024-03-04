class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int fuel = 0;
        int starting_point = 0;
        int totalFuel = 0;
        int totalCost = 0;
        for(int i = 0; i < n; i++){
            // Only for checking if solution doesn't exist
            totalFuel += gas[i];
            totalCost += cost[i];
            // Only for checking if solution doesn't exist
            
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                starting_point = i + 1;
                fuel = 0;
            }
        }
        return totalFuel < totalCost ? -1 : starting_point;
    }
};