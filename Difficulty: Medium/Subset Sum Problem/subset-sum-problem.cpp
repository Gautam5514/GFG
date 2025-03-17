//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
          vector<int> bottom(sum+1, 0); bottom[sum] = 1;
        vector<int> top(sum+1, 0);
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            for(int j=0; j<=sum; j++)
            {
                int v1 = bottom[j];
                int v2 = (j + arr[i]) <= sum ? bottom[j + arr[i]] : 0;
                top[j] = v1 | v2;
                bottom[j] = top[j];
            }
        }
        
        return top[0];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends