//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                   // check for all possible of dir
                   for(int k = 0; k < 4; k++) {
                       int ni = i + dir[k][0];
                       int nj = j + dir[k][1];
                       
                       // check if the neighbour is within bound and is a 1
                       if(ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] == 1) {
                           count++;
                       }
                   }
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends