//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
     vector<int> ans;
    int n = nums.size();
    
    if (n == 0) return {-1};  // Edge case: Empty array
    if (n == 1 || n == 2) return nums;  // Edge case: If array has less than 3 elements
    
    // Sort the array to group duplicates together
    sort(nums.begin(), nums.end());
    
    int count = 1;  // Start counting from 1
    
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;  // Increment count if current number matches the previous one
        } else {
            if (count > n / 3) {  // Check if the count of the previous number is greater than n/3
                ans.push_back(nums[i - 1]);
            }
            count = 1;  // Reset count for the new number
        }
    }
    
    // After the loop, we need to check the last element
    if (count > n / 3) {
        ans.push_back(nums[n - 1]);
    }
    
    if (ans.empty()) return {-1};  // If no majority elements found, return -1
    
    return ans;  // Return the list of majority elements
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends