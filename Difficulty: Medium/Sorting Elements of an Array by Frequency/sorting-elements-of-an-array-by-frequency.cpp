//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
         int n = arr.size();

    // Create a frequency map
    unordered_map<int, int> freqMap;
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Custom comparator using a lambda function
    sort(arr.begin(), arr.end(), [&](int a, int b) {
        // Compare by frequency first
        if (freqMap[a] != freqMap[b]) {
            return freqMap[a] > freqMap[b]; // Higher frequency comes first
        }
        // If frequencies are the same, compare by value
        return a < b; // Smaller value comes first
    });

    return arr; // Return the sorted array
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends