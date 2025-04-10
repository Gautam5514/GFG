//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int manhattan(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}
    int minCost(vector<vector<int>>& houses) {
        // code here
    int n = houses.size();
    vector<bool> visited(n, false);
    vector<int> minDist(n, INT_MAX);
    minDist[0] = 0;

    int totalCost = 0;

    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }
            visited[u] = true;
            totalCost += minDist[u];
            
            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int dist =  manhattan(houses[u], houses[v]);
                    if(dist < minDist[v])
                    minDist[v] = dist;
                }
            }
        }
        return totalCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends