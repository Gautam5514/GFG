//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
         int n = s.size();
    unordered_map<char, int> charIndex; // To store the index of characters in the current window
    int maxLength = 0; // To store the result
    int start = 0; // Left pointer of the window

    // Traverse the string
    for (int end = 0; end < n; end++) {
        char currentChar = s[end];

        // If the character is already in the window, move `start` pointer
        if (charIndex.find(currentChar) != charIndex.end()) {
            start = max(start, charIndex[currentChar] + 1);
        }

        // Update the character's index
        charIndex[currentChar] = end;

        // Update the maximum length of unique substring
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends