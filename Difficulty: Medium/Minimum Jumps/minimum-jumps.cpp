//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
          int n=arr.size();
        if(arr[0]==0) return -1;
        
        int fuel=arr[0], jump=1, maxi=arr[0];
        
        for(int i=1; i<n; i++){
            if (i == n - 1) return jump;
            fuel--;
            maxi=max(maxi, i+arr[i]);
            if(fuel==0){
                if(maxi<=i) return -1;
                else{
                    fuel=maxi-i;
                    jump++;
                }
            }
        }
        return jump;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends