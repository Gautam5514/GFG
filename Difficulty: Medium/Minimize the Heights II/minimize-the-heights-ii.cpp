class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
         sort(arr.begin(), arr.end());
        int n = arr.size();
        int smallest = arr[0] + k;
        int largest  = arr[n-1] - k;

        int ans = arr[n-1] - arr[0];
        for(int i = 0; i < n-1; i++)
        {
            int minimum = min(smallest, arr[i+1] - k);
            int maximum = max(largest, arr[i] +k);
            if(minimum < 0)
                continue;
            ans = min(ans,maximum-minimum);
        }
        return ans;
    }
};