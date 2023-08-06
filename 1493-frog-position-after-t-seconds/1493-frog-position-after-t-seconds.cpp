class Solution {
public:
// observation
// while going down multiply with 1/edge_count <= for unvisited nodes only 
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adjList(n+1); //adjList
        vector<bool> vis(n+1,0);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<double> prob(n+1,0);
        queue<int> q;
        q.push(1); // starts from 1
        vis[1] = 1;
        prob[1] = 1.0; // prob of reaching 1
        while(!q.empty() and t--){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                int edge_count = 0;
                for(auto e : adjList[node]){
                    if(!vis[e])
                        edge_count++;
                }
                for(auto v : adjList[node]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                        prob[v] = prob[node]*(1.00/edge_count);
                    }
                }
                //the only tricky part
                //A frog cannot stay at a fixed postion until there's no more vertex to jump
                if(edge_count > 0)
                    prob[node] = 0;
            }

        }
        return prob[target];
    }
};

// As given in the question description, in 1 second the frog jumps to its neighboring unvisited nodes if there is any, that means the frog is always in motion. So if at 'x' second, suppose the frog is at node 'n' and there are some unvisited nodes from the current node and also there is some time remaining for the frog 't-x', so in that case the frog will surely have to jump to the next unvisited node and so in this way, it makes the probability to reach the node 'n' at time 't' equal to 0 because the frog already reached the node 'n' at time 'x' and with further advancement in time, it had to jump to other nodes and as the frog can't jump back to the visited nodes, so this makes the probability to reach the node 'n' at time 't' equal to 0 because the frog already reached the node 'n' at time 'x' (not at time 't').