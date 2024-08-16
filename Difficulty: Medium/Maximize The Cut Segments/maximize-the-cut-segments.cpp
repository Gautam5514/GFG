//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[100001];
    int solve(int n, int x, int y, int z) {
        if(n == 0) return 0;
        if(dp[n]!= -1) return dp[n];
        int ans = INT_MIN;
        if(n-x >= 0) ans = max(ans, 1+solve(n-x,x,y,z));
        if(n-z>= 0) ans = max(ans, 1+solve(n-z,x,y,z));
        if(n-y>= 0) ans = max(ans, 1+solve(n-y,x,y,z));
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp, -1, sizeof(dp));
        solve(n,x,y,z);
        return dp[n]<0 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends