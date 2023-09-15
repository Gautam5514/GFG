//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int find(int idx,int sumR,vector<vector<int>>&dp,int arr[]){
        if(idx==-1 && sumR==0)return 1;
        if(idx<0 || sumR<0)return 0;
        if(dp[idx][sumR]!=-1)return dp[idx][sumR];
        return dp[idx][sumR]=find(idx-1,sumR,dp,arr)|find(idx-1,sumR-arr[idx],dp,arr);
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2)return 0;
        vector<vector<int>> dp(N,vector<int>(sum/2+1,-1));
        return find(N-1,sum/2,dp,arr);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends