//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int m, int n) {
        if(m < n) return 0;
        if(n == 0) return 1;
        
        if(dp[m][n] != -1) return dp[m][n];
        
        return dp[m][n] = solve(m/2, n-1) + solve(m-1, n); 
    }
    int numberSequence(int m, int n){
        memset(dp, -1, sizeof(dp));
        return solve(m, n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends