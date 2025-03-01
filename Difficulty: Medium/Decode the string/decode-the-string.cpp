//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<int> numStack;
        stack<string> strStack;
        string currentStr = "";
        int num = 0;
        
        for(char ch : s){
            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if(ch == '[') {
                numStack.push(num);
                strStack.push(currentStr);
                num = 0;
                currentStr = "";
            } else if(ch == ']') {
                int repeatCount= numStack.top(); numStack.pop();
                string temp =  strStack.top(); strStack.pop();
                
                while(repeatCount--) {
                    temp += currentStr;
                }
                currentStr = temp;
            } else {
                currentStr += ch;
            }
        }
        return currentStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends