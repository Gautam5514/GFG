//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p) {
    int minLen = INT_MAX; // Minimum length of window
    int ind = -1; // Start index of the minimum window
    int r = 0, l = 0; // Right and Left pointers
    vector<int> mp(256, 0); // Frequency map for characters in `p`

    // Fill the frequency map for `p`
    for (int i = 0; i < p.size(); i++) {
        mp[p[i]]++;
    }

    int cnt = 0; // Count of characters matched

    while (r < s.length()) {
        // If current character in `s` is part of `p`
        if (mp[s[r]] > 0) {
            cnt++;
        }
        mp[s[r]]--; // Decrease frequency of the character
        r++; // Move right pointer

        // When all characters are matched
        while (cnt == p.size()) {
            // Update the minimum window size and index
            if (r - l < minLen) {
                minLen = r - l;
                ind = l;
            }

            // Restore character for `l` pointer and move left pointer
            mp[s[l]]++;
            // If character is part of `p` and is needed again
            if (mp[s[l]] > 0) {
                cnt--;
            }
            l++; // Move left pointer
        }
    }
    // Return the result based on `ind`
    return ind == -1 ? "-1" : s.substr(ind, minLen);
}

};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends