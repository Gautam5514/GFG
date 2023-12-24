//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
         priority_queue<pair<int,int>>pq;
        
        for(int i = 0;i<n;++i) {
            pq.push({-price[i],i+1});
        }
        int ct = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int count = curr.second;
            int cost = -1*curr.first;
            
            if(cost <= k) {
               while(count--) {
                   if(k-cost >= 0) {
                       ct++;
                       k = k - cost;
                   }
                   else break;
               }
            }
            else break;
        }
        
        return ct;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends