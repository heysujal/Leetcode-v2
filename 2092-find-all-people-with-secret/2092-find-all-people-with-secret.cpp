class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first) {
        // time -> pairs of meet
        // it will get sorted according to time automatically!
        map<int, vector<pair<int, int>>> timeMeet;
        for(auto &meet : meetings){
            int time = meet[2];
            int person1 = meet[0];
            int person2 = meet[1];
            timeMeet[time].push_back({person1, person2});
        }

        vector<bool> secret(n, false);
        secret[0] = true;
        secret[first] = true;
        // solve in increasing time meetings
        for(auto &[time, meets] : timeMeet){
            // meets is vector of pairs
            // making adjacency list
            unordered_map<int, vector<int>> adj;
            queue<int> q;
            // to avoid bfs of repetitve persons
            unordered_set<int> alreadyAdded;
            
            for(auto &[p1, p2] : meets){
                adj[p1].push_back(p2);
                adj[p2].push_back(p1);
                // also add the persons who knows the secret already to do BFS
                if(secret[p1] and alreadyAdded.find(p1) == alreadyAdded.end()){
                    q.push(p1);
                    alreadyAdded.insert(p1);
                }
                if(secret[p2] and alreadyAdded.find(p2) == alreadyAdded.end()){
                    q.push(p2);
                    alreadyAdded.insert(p2);
                }
            }

            // let's spread the secret
            while(!q.empty()){
                int person = q.front();
                q.pop();

                for(auto &it : adj[person]){
                    if(secret[it] == false){
                        secret[it] = true;
                        alreadyAdded.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(secret[i] == true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};