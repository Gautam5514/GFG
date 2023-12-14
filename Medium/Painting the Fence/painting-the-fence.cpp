//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:

    long long countWays(int n, int k){
        long long total = k, same = 0, diff = k, mod = 1e9 + 7;
        for(int i = 2; i <= n; i++){
            same = diff;
            diff = (total%mod*(k - 1)%mod)%mod;
            total = (same + diff)%mod;
        }
        return total;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends