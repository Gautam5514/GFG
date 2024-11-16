//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
         int n = arr.size();
        
        //initialize the vector ans to 0
        vector<int> ans(n,0);
        
        int j = 0;

        for(int i = 0 ; i < n ; i++) // normal traversing 
        {
            if(arr[i] != 0)
                ans[j++] = arr[i]; //storing only the non-zero element on its correct position
        }
        
        arr = ans; // copying the vector array 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends