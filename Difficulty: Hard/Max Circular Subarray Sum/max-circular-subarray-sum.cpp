class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int total = 0;
        
        int maxSum = arr[0], curMax = 0;
        int minSum = arr[0], curMin = 0;
        
        for(auto a : arr) {
            
            // find the max
            
            curMax = max(a, curMax + a);
            maxSum = max(maxSum, curMax);
            
            // find the min
            
            curMin = min(a, curMin + a);
            minSum = min(minSum, curMin);
            
            total += a;
        }
        
        if(maxSum < 0) return maxSum;
        
        return max(maxSum, total - minSum);
    }
};