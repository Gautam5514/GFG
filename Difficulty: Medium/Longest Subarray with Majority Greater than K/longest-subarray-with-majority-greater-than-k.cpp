//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int ans = 0;
        int cnt = 0;
        
        unordered_map <int, int> mp;
        for(int i = -n-1; i <= n+1; i++) mp[i] = -1;
        
        mp[0] = 0;
        for(int i = 0; i < n; i++){
            cnt += (arr[i] > k);
            cnt -= (arr[i] <= k);
            
            if(mp[cnt] == -1) mp[cnt] = i;
            if(cnt > 0) ans = i+1;
            else if(mp[cnt-1] != -1) ans = max(ans, i - mp[cnt-1]);
        }
        
        return ans;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends