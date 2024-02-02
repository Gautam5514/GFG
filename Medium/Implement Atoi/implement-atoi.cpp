//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans = 0;
        int sign = 1;
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '-' && i == 0) {
                sign = -1;
            }
            else if(s[i]>= '0' && s[i]<= '9') {
                ans = ans * 10 + (s[i] - '0');
            }
            else return -1;
        }
        ans = ans * sign;
        return ans;
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
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends