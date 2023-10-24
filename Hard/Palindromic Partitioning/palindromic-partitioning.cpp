//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool check(string s){
        for(int i=0;i<s.size()/2;i++)if(s[i]!=s[s.size()-1-i])return 0;
        return 1;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        vector<int>dp(n+1,1e7);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(str.substr(i,(j-i+1)))){
                if(i==0) dp[j]=1;
                else dp[j]=min(dp[j],dp[i-1]+1);}
            }
        }
        return dp[n-1]-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends