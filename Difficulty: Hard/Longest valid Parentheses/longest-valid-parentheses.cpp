//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        int maxLength = 0;
        // left to right
        int left = 0, right = 0;
        for(char c : str) {
            if(c == '(') left++;
            if(c == ')') right++;
            if(left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if(right > left) {
                left = right = 0; // reset counter
            }
        }
        // right to left
        left = right = 0;
        for(int i = str.size() - 1; i>= 0; i--) {
            if(str[i] == '(') left++;
            if(str[i] == ')') right++;
            if(left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxLength;
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
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends