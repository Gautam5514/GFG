//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
       int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i == 0 || i == m-1 )||(j == 0 || j == n-1)) bfs(grid, i, j, m, n);
            }
        }    
        for(int i = 1; i<m-1; i++){
            for(int j = 1; j<n-1; j++){
                if(grid[i][j] == 1) count++;
            }
        }    
        return count;
        
    }
    
    void bfs(vector<vector<int>> &grid, int a, int b, int m, int n){
        
       if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] != 1) {
        return;
    }
    
    grid[a][b] = 2;
    bfs(grid, a-1, b, m, n);
    bfs(grid, a+1, b, m, n);
    bfs(grid, a, b-1, m, n);
    bfs(grid, a, b+1, m, n);
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends