//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int n = s1.length();
        int m = s2.length();
        
        if(n != m) {
            return false;
        }
        
        int i = 0, j = 0;
        while(i < n) {
            if(s1[i++] != s2[j++])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends