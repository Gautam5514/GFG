//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
           int n=val.size();
       
    vector<int> prev(W+1,0),cur(W+1,0);
       
        for(int w=wt[0];w<=W;w++) prev[w] = val[0];
        
       for(int i=1;i<n;i++){
           for(int w=1;w<=W;w++){
               int pick=INT_MIN;
               if(wt[i]<=w)  pick= val[i] + prev[w-wt[i]];
               int notPick = prev[w];
               
               cur[w]=max(pick,notPick);
            
           }
           prev=cur;
       }
       
       return prev[W];
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends