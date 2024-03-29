//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        int a = countSub(str1);
        int b = countSub(str2);
        if(a < b){
            return str2;
        }
        return str1;
    }
    static int countSub(const string &str){
        unordered_map<char, int> last;
        int n = str.length();
        int dp[n+1];
        dp[0]=1;
        for(int i = 1; i<= n; i++){
            dp[i] = 2*dp[i-1];
            if(last.find(str[i-1]) != last.end()){
                dp[i] = dp[i]-dp[last[str[i-1]]];
            }
            last[str[i-1]] = i-1;
        }
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends