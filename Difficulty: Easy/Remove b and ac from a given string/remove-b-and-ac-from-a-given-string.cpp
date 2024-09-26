//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
  public:
  void helper(string &str, int idx, stringstream& result) {
      
      int n = str.length();
      
      if(idx == n) {
          return;
      }
      char curr = str[idx];
      
      if(curr == 'b') {
          return helper(str, idx + 1, result);
      }
      else if(curr == 'a' && idx + 1 < n && str[idx + 1] == 'c') {
          return helper(str, idx + 2, result);
      }
      else {
          result << curr;
           helper(str, idx + 1, result);
      }
  }
    string stringFilter(string& str) 
    { 
        //code here.
        stringstream result;
        helper(str, 0, result);
        return result.str(); // convert the streamstring to string
    } 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;
   		
   		Solution ob;
   		cout <<ob.stringFilter(s) << "\n";

   		
   	}

    return 0;
}
// } Driver Code Ends