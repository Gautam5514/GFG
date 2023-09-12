//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        // int rem;
        // int sum = 0;
        // for(int i = 1; i<N; i++){
        //     rem = N%i;
        //     if(rem == 0)
        //     {
        //         sum = sum+i;
        //     }
        //     if(sum == N)
        //     return 1;
        // }
        // return 0;
        long long sum = 0;
        for(int i = 2; i<=sqrt(N); i++)
        {
            
            if(N%i == 0){
            if(i !=N/i)
            {
                sum += (i + N/i);
            }
            else
            {
                sum += i;
            }
        }
        }
        return N!=1 && sum+1 == N;
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends