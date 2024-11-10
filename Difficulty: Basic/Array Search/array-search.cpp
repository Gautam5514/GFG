//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to search x in arr
    // arr: input array
    // X: element to be searched for
    int recursionsearch(vector<int>& arr, int i, int x) {
        if(i == arr.size()) return -1;
        
        if(arr[i] == x) return i;
        
        return recursionsearch(arr, i + 1, x);
    }
    int search(vector<int>& arr, int x) {

        
        return recursionsearch(arr, 0, x);
    }
};

//{ Driver Code Starts.

int main() {
    int testcases;
    cin >> testcases;
    cin.ignore(); // To ignore the newline character after reading testcases
    while (testcases--) {
        vector<int> arr;
        int x;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, input); // Read the next line for x
        stringstream ss2(input);
        ss2 >> x;

        Solution ob;
        cout << ob.search(arr, x) << endl; // Linear search
        cout << '~' << endl;
    }

    return 0;
}
// } Driver Code Ends