//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq; // stores indices
    vector<int> ans;
    int n = arr.size();

    // Process first window of size k
    for(int i = 0; i < k; i++) {
        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);

    // Process rest of the array
    for(int i = k; i < n; i++) {
        // Remove indices that are out of the current window
        if(!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element from the back
        while(!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i); // Add current index
        ans.push_back(arr[dq.front()]); // Front of deque is the largest element
    }

    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends