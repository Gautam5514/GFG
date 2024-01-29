//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[21][21][21];
int help(string A,string B,string C,int n1,int n2,int n3){
    if(n1==0 || n2==0 || n3==0) return 0;
    if(dp[n1][n2][n3]!=-1) return dp[n1][n2][n3];
    if(A[n1-1]==B[n2-1] && B[n2-1] == C[n3-1]) 
    return dp[n1][n2][n3]=1+help(A,B,C,n1-1,n2-1,n3-1);
    else{
      return dp[n1][n2][n3]=max(help(A,B,C,n1,n2,n3-1),max(help(A,B,C,n1-1,n2,n3),help(A,B,C,n1,n2-1,n3)));  
    }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
 memset(dp,-1,sizeof(dp));
 int ans=help(A,B,C,n1,n2,n3);
 return ans;
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends