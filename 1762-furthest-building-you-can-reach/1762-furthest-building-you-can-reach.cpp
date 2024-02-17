class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        int n = height.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        int i;
        for(i = 1; i < n; i++){
            int diff = height[i] - height[i-1];
            if(diff > 0){
                pq.push(diff);
            }
            else{
                continue;
            }
            if(pq.size() > ladders){
                bricks -= pq.top();
                pq.pop();
            }
            if(bricks < 0){
                return i-1;
            }
        }
        return n-1;
    }
};