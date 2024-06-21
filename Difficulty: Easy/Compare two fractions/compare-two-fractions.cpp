//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int a, b, c, d;
        
        char dummy;
        stringstream ss(str);
        ss >> a >> dummy >> b >> dummy >> c >> dummy >> d;
        
        int lhs = a * d;
        int rhs = c * b;
        
        if(lhs > rhs) {
            return to_string(a) + "/" + to_string(b);
            } else if(lhs < rhs) {
                return to_string(c) + "/" + to_string(d);
            } else {
                return "equal";
            }
        }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends