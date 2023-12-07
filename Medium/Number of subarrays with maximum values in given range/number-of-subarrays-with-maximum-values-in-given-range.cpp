//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        long ans = 0;
        long btwLR = 0, lessL = 0;
        for(int i = 0; i<n; i++){
            if(a[i] < L){
                ans += btwLR;
                lessL++;
            }
            else if(a[i] > R){
                btwLR=lessL=0;
            }
            else {
                ans+=btwLR+lessL+1;
                btwLR+=lessL+1;
                lessL=0;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends