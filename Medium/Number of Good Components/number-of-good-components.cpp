//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  void dfs(int i, int s, vector<vector<int>> &adj, vector<int> &vis, bool &a, int &node) {
      vis[i] = 1;
      node++;
      if(s!=adj[i].size()) {
          a = false;
      }
      for(auto x : adj[i]) {
          if(!vis[x]) dfs(x, s, adj, vis, a, node);
      }
  }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(v + 1);
        for( auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans = 0;
        vector<int> vis(v+1, 0);
        for(int i = 1; i <= v; i++) {
            if(!vis[i]) {
                int node = 0;
                bool a = true;
                dfs(i, adj[i].size(), adj, vis, a, node);
                if(a and node - 1 == adj[i].size()) ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends