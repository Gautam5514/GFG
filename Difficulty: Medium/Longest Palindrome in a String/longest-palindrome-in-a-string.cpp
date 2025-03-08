//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)dp[i][i]=1;
        int maxLen=1;
        int start=-1;
        for(int L=2;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(s[i]==s[j]){
                    if(L==2)dp[i][j]=2;
                    else if(dp[i+1][j-1]>0) dp[i][j]=2+dp[i+1][j-1];
                    else dp[i][j]=0;
                }
                if(dp[i][j]>0){
                    if(j-i+1>maxLen){
                        maxLen=max(maxLen,j-i+1);
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends