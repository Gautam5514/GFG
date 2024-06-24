//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q < 2 || q > 2 * n) {
            return 0;
        }
        long long max_i = max(1LL, q - n);
        long long min_i = min(q - 1, n);
        
        long long count = max_i <= min_i ? (min_i - max_i + 1) : 0;
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends