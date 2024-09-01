//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int sum = 0;
        int Original = n;
        // find the total length from  the armstrong number
        int k = to_string(n).length();
        while(n > 0) {
            int temp = n % 10;
            sum += pow(temp, k);
            n /= 10;
        }
        if(Original == sum) {
            return "true";
        } else {
            return "false";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends