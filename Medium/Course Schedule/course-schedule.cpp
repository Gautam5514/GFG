//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
   vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
{
    // Create adjacency list
    vector<int> adj[n];
    vector<int> indegree(n, 0);
    
    // Populate adjacency list and calculate indegrees
    for(auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }

    // Initialize queue with nodes having 0 indegree
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        // Update indegrees of adjacent nodes
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // Check if a valid topological order is possible
    if(topo.size() == n) {
        return topo;
    }
    return {}; // Return an empty vector if no valid topological order exists
}

};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends