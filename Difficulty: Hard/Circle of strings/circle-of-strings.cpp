//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void DFS(int node, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;
    for (int j = 0; j < adj[node].size(); j++) {
        if (!visited[adj[node][j]]) {
            DFS(adj[node][j], adj, visited);
        }
    }
}

int isCircle(vector<string>& arr) {
    int n = arr.size();
    vector<int> adj[26];
    vector<int> inDeg(26, 0);
    vector<int> outDeg(26, 0);

    for (int i = 0; i < n; i++) {
        string temp = arr[i];

        int u = temp[0] - 'a';
        int v = temp[temp.size() - 1] - 'a';
        adj[u].push_back(v);
        outDeg[u]++;
        inDeg[v]++;
    }

    // Check if in-degree equals out-degree for every character
    for (int i = 0; i < 26; i++) {
        if (inDeg[i] != outDeg[i]) {
            return 0;
        }
    }

    // Perform DFS from the first character of the first string
    vector<int> visited(26, 0);
    int startNode = arr[0][0] - 'a';

    // Start DFS from a node that has outgoing edges
    DFS(startNode, adj, visited);

    // Check if all characters that have in-degree or out-degree are visited
    for (int i = 0; i < 26; i++) {
        if ((inDeg[i] > 0 || outDeg[i] > 0) && !visited[i]) {
            return 0;
        }
    }

    return 1;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends