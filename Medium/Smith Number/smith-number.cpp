//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sumDigit(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x=x/10;
        }
        return sum;
    }
    
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
   int smithNum(int n) {
        int sum=sumDigit(n);
        int sum2=0;
        if(isPrime(n)) return 0;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                int s=sumDigit(i);
                while( n>0 && n%i==0){
                    sum2+=s;
                    n=n/i;
                }
            }
        }
        if(sum==sum2) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends