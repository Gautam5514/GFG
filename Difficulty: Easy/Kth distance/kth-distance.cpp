//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        unordered_map<int, int> mp;
        int n = arr.size();
        if(n == 1) return false; // not any repeted no.
        for(int i = 0; i <= k; i++) {
            mp[arr[i]]++;
            if(mp[arr[i]] > 1) return true; // there is exist more than 1
        }
        int last = 0; // if move forward then back is indicate 0 in map
        for(int i = k + 1; i < n; i++) {
            mp[arr[last++]]--;
            mp[arr[i]]++;
            if(mp[arr[i]] > 1) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends