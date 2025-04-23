//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size() + 1;
        
        // create a variable where store all the sum of n
        int sum = 0;
        for(int i = 1; i <= n; i++) 
            sum += i;
        
        // now create one more variable which is store the our arr value
        int actual_sum = 0;
        for(int i = 0; i < arr.size(); i++) 
            actual_sum += arr[i];
        
        
        return sum - actual_sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.missingNum(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends