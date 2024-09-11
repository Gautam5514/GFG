//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isFactorial(int N){
        // Write the base case
        if(N == 1) return 1;
        
        int fact = 1;
        
        for(int i = 1; i <= N; i++) {
            fact = fact * i;
       
        if(fact == N) {
            return 1;
        }
        if(fact > N) {
            return 0;
        }
        
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isFactorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends