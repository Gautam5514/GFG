//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        if(n <= 2) return 1;
        
        int a = 1, b = 1, c = 1, temp = 0, mod = 1e9+7;
        
        for(int i = 3; i <= n; i++) {
            temp = (a + b) % mod;
            a = b;
            b = c;
            c = temp;
        }
        return c;
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
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends