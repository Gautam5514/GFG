//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool cmp(int mid,int arr[],int N,int K){
        int count=1;
        int sum=0;
        for(int i=0;i<N;i++){
            if(arr[i]>mid) return 1;
            else if(arr[i]+sum<=mid){
                sum+=arr[i];
            }
            else{
                sum=arr[i];
                count++;
            }
        }
        if(count<=K) return 0;
        return 1;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        int l=0,h=sum;
        while(h-l>1){
            int mid=(h+l)/2;
            if(cmp(mid,arr,N,K)){
                l=mid;
            }
            else{
                h=mid;
            }
        }
        return h;


    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends