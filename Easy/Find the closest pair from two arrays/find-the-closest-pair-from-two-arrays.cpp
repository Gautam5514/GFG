//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        vector<int>v;
        int i = 0,j=m-1;
        int res=INT_MAX;
        while(i<n and j>=0){
            if(x-arr[i]-brr[j]<0){
                res=min(res,abs(x-arr[i]-brr[j]));
                j--;
            }
            else if((x-arr[i]-brr[j])>=0){
                res=min(res,(x-arr[i]-brr[j]));
                i++;
            }
        }
        res=x-res;
        v.push_back(res);
        
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends