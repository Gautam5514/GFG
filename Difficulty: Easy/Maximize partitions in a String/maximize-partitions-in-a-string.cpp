//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int maxPartitions(string &s) {
    unordered_map<char, int> lastIndex;
    int n = s.size();

    // Step 1: Store last occurrence of each character
    for (int i = 0; i < n; i++) {
        lastIndex[s[i]] = i;
    }

    int count = 0;
    int partitionEnd = 0;

    // Step 2: Greedy partitioning
    for (int i = 0; i < n; i++) {
        partitionEnd = max(partitionEnd, lastIndex[s[i]]); // Expand to include all occurrences
        if (i == partitionEnd) { // If we reach partition end, count this as a partition
            count++;
        }
    }
    return count;
}
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends