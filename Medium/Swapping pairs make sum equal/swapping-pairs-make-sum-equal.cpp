//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
         int sum1 = 0,sum2=0;
        for(int i=0;i<n;i++) sum1 += a[i];
        for(int i=0;i<m;i++) sum2 += b[i];
        sort(a,a+n);
        sort(b,b+m);
        for(int i=0;i<n;i++){
             int val = sum1 - a[i];
             int inc = sum2 + a[i];
             int diff = inc-val;
             if(diff%2==0 && binary_search(b,b+m,diff/2)) return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends