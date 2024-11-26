//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    // find the maximum subarray using kadane algo
    int kadaneMax(vector<int> arr) {
        int maxEnd = 0, maxSoFar = INT_MIN;
        for(int num : arr) {
            maxEnd = max(num, maxEnd + num);
            maxSoFar = max(maxSoFar, maxEnd);
        }
        return maxSoFar;
    }
    
    int kadaneMin(vector<int> arr) {
        int minEnd = 0, minSoFar = INT_MAX;
        for(int num : arr) {
            minEnd = min(num, minEnd + num);
            minSoFar = min(minSoFar, minEnd);
        }
        return minSoFar;
    }
    int circularSubarraySum(vector<int> &arr) {
        int maxKadane = kadaneMax(arr);// straight max arr sum
        int totalSum = accumulate(arr.begin(), arr.end(), 0); //total array
        int minKadane = kadaneMin(arr); // min subarray sum
        
        // all element are negative
        if(totalSum == minKadane) {
            return maxKadane;
        }
        // max circular array
        int circularMax = totalSum - minKadane;
        return max(maxKadane, circularMax);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends