//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(vector<int> arr, int n, int i, int sum, vector<int>& result) {
      if(i == n) {
          result.push_back(sum);
          return;
      }
      
      solve(arr, n, i + 1, sum + arr[i], result);
      
      solve(arr, n, i + 1, sum, result);
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> result;
        
        solve(arr, n, 0, 0, result);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends