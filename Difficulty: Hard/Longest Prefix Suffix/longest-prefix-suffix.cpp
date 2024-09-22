//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n = str.size();
        vector<int> llps(n, 0);
        int i = 1;
        int len = 0;
        
        while(i < n) {
            if(str[i] == str[len]) {
                len++;
                llps[i] = len;
                i++;
            } else {
                if(len != 0) {
                    len = llps[len - 1];
                } else {
                    llps[i] = 0;
                    i++;
                }
            }
        }
        return llps[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends