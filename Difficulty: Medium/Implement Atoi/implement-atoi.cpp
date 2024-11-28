//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
    long long ans = 0; // Use long long to handle intermediate overflow
    int i = 0, n = strlen(s);
    int sign = 1; // Default sign is positive

    // Skip leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // Handle the sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Process digits
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0');

        // Check for overflow/underflow
        if (sign * ans > INT_MAX) return INT_MAX;
        if (sign * ans < INT_MIN) return INT_MIN;

        i++;
    }

    return static_cast<int>(ans * sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends