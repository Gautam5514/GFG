//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
         long long arr_sum = 0;
    long long curr_sum = 0;
    
    // Calculate the sum of array elements and the initial value of the sum of i * a[i]
    for(int i = 0; i < n; i++) {
        arr_sum += a[i];
        curr_sum += i * static_cast<long long>(a[i]);
    }
    
    // Initialize max_sum with the current sum
    long long max_sum = curr_sum;
    
    // Calculate the sum for all rotations and find the maximum
    for(int i = 1; i < n; i++) {
        curr_sum = curr_sum - arr_sum + n * static_cast<long long>(a[i - 1]);
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends