//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        string s1 = "";
        string s2 = "";
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                s1 += to_string(arr[i]);
            } else {
                s2 += to_string(arr[i]);
            }
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        string ans = "";
        int i = 0;
        int carry = 0;
        while(i < s1.size() || i < s2.size() || carry) {
            int sum = 0;
            if(i < s1.size())
            sum += s1[i] - '0';
            if(i < s2.size())
            sum += s2[i] - '0';
            
            sum += carry;
            ans += to_string(sum % 10);
            carry = sum / 10;
            i++;
        } 
        while(ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends