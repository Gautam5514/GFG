//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
    vector<long long> result;
    
    long long fact = 1;

    // Use a for loop to generate factorials until the value exceeds n
    for (long long i = 1; fact <= n; i++) {
        result.push_back(fact);  // Add the current factorial to the result list
        fact *= i + 1;  // Compute the next factorial (i+1)!
    }

    return result;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends