//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
       int minZero = INT_MAX;  // Initialize to a large value
    int minZeroRow = -1;    // Track the row with the minimum zeros
    
    for(int i = 0; i < n; i++) {  // Loop through each row
        int no_Zero = 0;
        for(int j = 0; j < m; j++) {  // Count the number of zeros in the current row
            if(a[i][j] == 1) no_Zero++;
        }
        
        // Update if the current row has fewer or the same number of zeros
        if(no_Zero < minZero) {
            minZero = no_Zero;
            minZeroRow = i;
        }
    }
    
    return minZeroRow +1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends