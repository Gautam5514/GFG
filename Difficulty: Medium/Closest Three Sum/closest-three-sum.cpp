//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
            int n = arr.size();
    int closestSum = INT_MAX;
    int minDiff = INT_MAX;
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right) {
            int currSum = arr[i] + arr[left] + arr[right];
            int currDiff = abs(currSum - target);
            
            if (currDiff < minDiff) {
                minDiff = currDiff;
                closestSum = currSum;
            } else if (currDiff == minDiff) {
                closestSum = max(closestSum, currSum);
            }
            
            if (currSum < target) {
                ++left;
            } else if (currSum > target) {
                --right;
            } else {
                // If the currentSum is exactly equal to the target, return it
                return currSum;
            }
        }
    }
    
    return closestSum;
  }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends