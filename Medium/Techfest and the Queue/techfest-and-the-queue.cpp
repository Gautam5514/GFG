//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int helper(int n) {
        int id = 2; 
        int count = 0;
        while(id * id <= n) {
            if(n % id == 0) {
                n/= id;
                count++;
            }
            else {
                id++;
            }
        }
        if(n != 1) count++;
        return count;
    }
	int sumOfPowers(int a, int b){
	    int count = 0;
	    for(int i = a; i <= b; i++) {
	        count += helper(i);
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends