//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        // make array to store all the value on that
        vector<int> arr(26, 0);
        string ans;
        int n = str.length();
        for(int i = 0; i < n; i++) {
            if(arr[str[i] - 'a'] != 0) {
                continue;
            } else {
                ans += str[i];
                arr[str[i]-'a']=1;
            }
        }
        return ans;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends