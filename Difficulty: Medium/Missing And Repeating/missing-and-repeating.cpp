//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
    long long n = arr.size();
    long long Sn = n * (n + 1) / 2;
    long long Sn2 = n * (n + 1) * (2 * n + 1) / 6;

    long long S = 0;
    long long S2 = 0;

    for (long long num : arr) {
        S += num;
        S2 += (long long)(num * num);
    }

    long long diff1 = S - Sn;
    long long diff2 = (S2 - Sn2) / diff1;

    long long x = (diff1 + diff2) / 2;
    long long y = diff2 - x;

    return {x,y}; // {repeating, missing}
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends