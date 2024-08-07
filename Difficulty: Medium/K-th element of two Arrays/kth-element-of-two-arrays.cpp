//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        if(arr1.size() > arr2.size()){
            return kthElement(k, arr2, arr1);
        }
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        int low = max(0, k - n2);
        int high = min(n1, k);
        
        while(low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = k - mid1;
            
            int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : arr1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : arr2[mid2];
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            } else if(l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends