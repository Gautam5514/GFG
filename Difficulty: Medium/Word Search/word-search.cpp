//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool dfs(vector<vector<char>>& mat, string &word, int i, int j, int index) {
      if(index == word.length()) {
          return true;
      }
      
      if(i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) {
          return false;
      }
      char temp = mat[i][j];
      mat[i][j] = '#';
      
      bool found = dfs(mat, word, i + 1, j, index + 1) ||
                   dfs(mat, word, i - 1, j, index + 1) ||
                   dfs(mat, word, i, j + 1, index + 1) ||
                   dfs(mat, word, i, j - 1, index + 1);
        
        mat[i][j] = temp;
        return found;
  }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
               if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                return true;
               }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends