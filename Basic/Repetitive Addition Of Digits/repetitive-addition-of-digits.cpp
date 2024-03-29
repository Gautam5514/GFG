//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int singleDigit(long long N)
    {
        // Write Your Code here
        long long sum = 0;
        while(N > 0 || sum > 9) {
            if(N == 0) {
                N = sum;
                sum = 0;
            }
            sum += N % 10;
            N /= 10;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends