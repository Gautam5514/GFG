//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
    if(N == 0) {
        cout << "0";  // Special case for N = 0
        return;
    }
    
    string binaryNumber = "";
    
    while(N > 0) {
        int remainder = (N % 2);  // Get remainder when dividing by 2 (either 0 or 1)
        binaryNumber = to_string(remainder) + binaryNumber;  // Prepend the remainder to the binary string
        N /= 2;  // Divide N by 2 to move to the next bit
    }
    
    cout << binaryNumber;  // Print the final binary string

}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends