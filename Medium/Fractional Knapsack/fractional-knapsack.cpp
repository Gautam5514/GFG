//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(const Item& a, const Item& b) {
        double r1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
        double r2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item* items, int n) {
        double ans = 0;
        std::sort(items, items + n, cmp);

        for (int i = 0; i < n; ++i) {
            if (items[i].weight <= W) {
                ans += items[i].value;
                W -= items[i].weight;
            } else {
                double fraction = static_cast<double>(W) / items[i].weight;
                ans += fraction * items[i].value;
                break; // Break out of the loop since the knapsack is full
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends