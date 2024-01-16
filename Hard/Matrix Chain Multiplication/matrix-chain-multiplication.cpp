//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int f(int i, int j, int arr[]){
        if(i == j || i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int k = i+1; k < j; k++) {
           ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i]*arr[k]*arr[j]);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp, -1, sizeof(dp));
        return f(0, N-1, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends