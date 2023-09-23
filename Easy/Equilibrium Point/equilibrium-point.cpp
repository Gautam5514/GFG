//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int i = 0, j = n-1;
        long long sum_i = 0, sum_j = 0;
        while(i < j){
            if(sum_i == sum_j){
                sum_i += a[i++];
                sum_j += a[j--];
            }
            else if(sum_i < sum_j)
            sum_i += a[i++];
            else
            sum_j += a[j--];
        }
        if(sum_i == sum_j) return i+1;
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends