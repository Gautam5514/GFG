//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> result(n);
        vector<int> positive, negative;
        
        for(int i = 0; i < n; i++) {
          if(arr[i] >= 0) {
              positive.push_back(arr[i]);
          } else {
              negative.push_back(arr[i]);
          }
        }
        // merge the negative and positive
        int negIndex = 0, posIndex = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0 && posIndex < positive.size()) {
                result[i] = positive[posIndex++];
            } else if(negIndex < negative.size()) {
                result[i] = negative[negIndex++];
            } else if(posIndex < positive.size()) {
                result[i] = positive[posIndex++];
            } else if(negIndex < negative.size()) {
                result[i] = negative[negIndex++];
            }
        }
        // copy the result back on the original array
        arr = result;
        
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends