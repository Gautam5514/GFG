class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        // Step 1: Place elements at their correct positions
        for(int i = 0; i < n; i++) {
            while(arr[i] >= 1 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Step 2: Find the first location where index doesn't match value
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all values from 1 to n are present, return n+1
        return n + 1;
    }
};