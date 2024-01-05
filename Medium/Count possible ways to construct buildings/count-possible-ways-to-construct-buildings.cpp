//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    if(N == 1) {
	        return 4;
	    }
	    if(N == 2) {
	        return 9;
	    }
	    long long int mod = 1e9+7;
	    int previous_two = 2;
	    int previous_one = 3;
	    int present = 0;
	    for(int i = 3; i <= N; i++) {
	        present = (previous_two + previous_one + mod)%mod;
	        previous_two = previous_one;
	        previous_one = present;
	    }
	    long long total = ((present%mod)*(present%mod))%mod;
	    return total;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends