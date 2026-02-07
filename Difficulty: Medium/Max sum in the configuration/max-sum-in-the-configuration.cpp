class Solution {
  public:
    int maxSum(vector<int> &arr) {
           int n = arr.size();
        
        int sum = 0;      // Sum of all elements
        int R0 = 0;       // Initial configuration value
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            R0 += i * arr[i];
        }
        
        int ans = R0;
        int curr = R0;
        
        // Try all rotations
        for(int i = n - 1; i > 0; i--) {
            curr = curr + sum - n * arr[i];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};