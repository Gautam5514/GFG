//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
     vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> res;
        if(num.empty()) return res;
        
        int n = num.size();
        sort(num.begin(), num.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                int target_2 = target-num[j]-num[i];
                int front = j+1;
                int right = n-1;
                
                while(front<right){
                    int two_sum = num[front]+num[right];
                    if(two_sum < target_2) front++;
                    else if(two_sum>target_2) right--;
                    else{
                        vector<int> quadrup(4,0);
                        quadrup[0] = num[i];
                        quadrup[1] = num[j];
                        quadrup[2] = num[front];
                        quadrup[3] = num[right];
                        res.push_back(quadrup);
                        while(front<right && num[front] == quadrup[2]) ++front;
                        while(front<right && num[right] == quadrup[3]) --right;
                        
                    }
                }
                
                while(j+1<n&& num[j+1] == num[j]) ++j;
            }
            while(i+1<n && num[i+1] == num[i]) ++i;
        }
        
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends