//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here
        vector<char> v(D, '0');
        if(9*D < S) {
            return "-1";
        }
       string result = "";
        S--;

        for (int i = D - 1; i > 0; i--) {
            int digit = min(S, 9);
            result = char('0' + digit) + result;
            S -= digit;
        }

        result = char('0' + S + 1) + result;

        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends