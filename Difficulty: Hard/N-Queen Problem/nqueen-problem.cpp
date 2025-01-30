//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<vector<int>> ans;
  bool isSafe(int row, int col, int n, vector<vector<int>>& board) {
      int j = col;
      while(j >= 0) {
          if(board[row][j] == 1) {
              return false;
          }
          j--;
      }
      int i = row;
      j = col;
      while(i >= 0 && j >= 0) {
          if(board[i][j] == 1) {
              return false;
          }
          i--;
          j--;
      }
      i = row, j = col;
      while(i < n && j >= 0) {
          if(board[i][j] == 1) {
              return false;
          }
          i++;
          j--;
      }
      return true;
  }
    void solve(int col, int n, vector<vector<int>>& board, vector<int>& temp) {
        if(col == n) {
            ans.push_back(temp);
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 1;
                temp.push_back(row + 1);
                solve(col + 1, n, board, temp);
                temp.pop_back();
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        if(n == 1) {
            return {{1}};
        }
        vector<vector<int>> board(n, vector<int> (n, 0));
        vector<int> temp;
        solve(0, n, board, temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends