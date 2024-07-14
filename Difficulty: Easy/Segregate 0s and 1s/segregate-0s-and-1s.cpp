//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        //return sort(arr.begin(), arr.end()); TC:- O(nlogn)
          int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Increment left index while we see 0 at left
        while (arr[left] == 0 && left < right) {
            left++;
        }
        
        // Decrement right index while we see 1 at right
        while (arr[right] == 1 && left < right) {
            right--;
        }

        // If left is smaller than right then there is a 1 at left
        // and a 0 at right. Exchange arr[left] and arr[right]
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
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
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends