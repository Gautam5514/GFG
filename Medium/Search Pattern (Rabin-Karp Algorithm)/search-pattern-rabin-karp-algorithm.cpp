//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> ans;
            int n = pattern.size();
            int m = text.size();
            for(int i = 0; i <= m; i++) {
                int j;
                for(j = 0; j <n; j++) {
                    if(text[i+j] == pattern[j])
                    continue;
                    else break;
                }
                if(j == n) 
                ans.push_back(1+i);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends