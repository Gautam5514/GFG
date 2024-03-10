//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	      unordered_set<char> seen;
    
    // Initialize a string to store the result
    string result = "";
    
    // Iterate through each character in the string
    for (char ch : str) {
        // Check if the character is not already seen
        if (seen.find(ch) == seen.end()) {
            // If not, add it to the result and mark it as seen
            result += ch;
            seen.insert(ch);
        }
    }
    
    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends