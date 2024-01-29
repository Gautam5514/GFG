//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int n;
	
	int t[101][10001];
	
	int solve(int idx, int prev_sum, string &str) {
	    if(idx >= n) {
	        return 1;
	    }
	    
	    if(t[idx][prev_sum] != -1) {
	        return t[idx][prev_sum];
	    }
	    
	    int result   = 0;
	    int curr_sum = 0;
	    for(int i = idx; i < n; i++) {
	        curr_sum += (str[i]-'0');
	        if(prev_sum <= curr_sum) {
	            result += solve(i+1, curr_sum, str);
	        }
	    }
	    
	    
	    return t[idx][prev_sum] = result;
	}
	
	int TotalCount(string str) {
	    n = str.length();
	    memset(t, -1, sizeof(t));
	    return solve(0, 0, str);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends