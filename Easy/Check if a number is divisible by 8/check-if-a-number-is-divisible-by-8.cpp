//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
         int n = s.length();
    
    // If the length of the string is less than 3, convert it to integer and check if it's divisible by 8
    if (n < 3) {
        int num = stoi(s);
        if (num % 8 == 0)
            return 1;
        else
            return -1;
    }
    
    // Otherwise, check if the last three digits are divisible by 8
    int last_three_digits = (s[n - 3] - '0') * 100 + (s[n - 2] - '0') * 10 + (s[n - 1] - '0');
    if (last_three_digits % 8 == 0)
        return 1;
    else
        return -1;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends