class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        // Step 1: Create adjacency list
        vector<pair<int,int>> adj[V];
        for(auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Step 2: Min heap (distance, node)
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;
        
        // Step 3: Distance & ways array
        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        pq.push({0, 0});
        
        // Step 4: Dijkstra
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            long long d = top.first;
            int node = top.second;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                // Case 1: Found shorter path
                if(d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                    
                    ways[adjNode] = ways[node]; // copy ways
                }
                
                // Case 2: Found another shortest path
                else if(d + wt == dist[adjNode]) {
                    ways[adjNode] += ways[node]; // add ways
                }
            }
        }
        
        return ways[V - 1];
    }
};