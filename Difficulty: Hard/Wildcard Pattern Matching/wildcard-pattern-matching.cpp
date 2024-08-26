//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
     int help(string pattern,string str,int i,int j,vector<vector<int>> &dp){
        if(i==pattern.length() and j==str.length())return 1;
        if(i==pattern.length())return 0;
        if(j==str.length() and pattern[i]=='*')return help(pattern,str,i+1,j,dp);
        if(j==str.length())return 0;
        if(pattern[i]!='?' and pattern[i]!='*' and pattern[i]!=str[j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a = 0, b = 0, c = 0;
        if(pattern[i]=='*'){
            a = help(pattern,str,i+1,j,dp);
            b = help(pattern,str,i,j+1,dp);
        }
        c = help(pattern,str,i+1,j+1,dp);
        return dp[i][j] = a|b|c;
    }
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        vector<vector<int>> dp(pattern.length(),vector<int>(str.length(),-1));
        return help(pattern,str,0,0,dp);
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends