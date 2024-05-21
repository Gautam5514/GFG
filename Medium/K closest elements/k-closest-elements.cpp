//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        vector<int> vec;
        int low=0,high=n-1,mid=0,mn=INT_MAX,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            int diff=abs(arr[mid]-x);
            if(diff<=mn){
                if(ans==-1)ans=mid;
                else{
                    if(diff==mn and arr[ans]<arr[mid]){
                        ans=mid;
                    }
                    if(diff<mn)ans=mid;
                }
                mn=diff;
            }
            if(arr[mid]<x)low=mid+1;
            else high=mid-1;
        }
        int total=0,i=ans-1,j=ans+1;
        if(arr[ans]!=x){
            vec.push_back(arr[ans]);
            total++;
        }
        while(total<k){
            if(i>=0 and j<n){
                if(abs(arr[i]-x)<abs(arr[j]-x))vec.push_back(arr[i--]);
                else vec.push_back(arr[j++]);
            }
            else if(i>=0)vec.push_back(arr[i--]);
            else vec.push_back(arr[j++]);
            total++;
        }
        return vec;
     }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends