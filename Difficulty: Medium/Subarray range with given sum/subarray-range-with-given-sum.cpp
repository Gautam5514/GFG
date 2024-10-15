//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(arr[i] + arr[j] == tar) {
        //             count++;
        //         }
        //     }
        // }
        // return count;
        
        // for(int i = 0; i < n; i++) {
        //     if(arr[i-1] + arr[i] == tar) {
        //         count++;
        //     }
        // }
        // return count;
        
        // int prefixSum = INT_MAX;
        // for(int i = 0; i < n; i++) {
        //     arr[i] += arr[i-1];
        //     count++;
        // }
        // return count;
        
    int n = arr.size();
    unordered_map<int, int> prefixSumCount;
    int currentSum = 0;
    int count = 0;

    // Initialize the map with prefix sum 0 count as 1
    prefixSumCount[0] = 1;

    for (int i = 0; i < n; i++) {
        // Calculate the running sum
        currentSum += arr[i];

        // Check if there's a subarray (ending at i) that sums to `tar`
        if (prefixSumCount.find(currentSum - tar) != prefixSumCount.end()) {
            count += prefixSumCount[currentSum - tar];
        }

        // Add the current sum to the prefix sum map
        prefixSumCount[currentSum]++;
    }

    return count;
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends