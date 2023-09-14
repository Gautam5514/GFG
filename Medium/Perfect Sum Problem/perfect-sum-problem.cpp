//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
const int mod = 1e9 + 7;
	int numberOfways(int i,int sum,int arr[],int n,vector<vector<int>> &dp){
        if(sum == 0 and i == n) return 1;
 
        if(i>=n || sum<0) return 0;
 
        if(dp[i][sum]!=-1) return dp[i][sum];
 
        int pick = numberOfways(i+1,sum-arr[i],arr,n,dp);
        int notPick = numberOfways(i+1,sum,arr,n,dp);
        return dp[i][sum] = (pick%mod+notPick%mod)%mod;
    }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        int totalSum=0;
        for(int i=0 ; i<n ; i++){
            totalSum+=arr[i];
        }
        if(totalSum<sum) return 0;
        vector<vector<int>> dp(n+1,vector<int>(totalSum+1,-1));
        int ans = numberOfways(0,sum,arr,n,dp);
        return ans;
    }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends