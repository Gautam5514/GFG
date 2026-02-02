class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
         int totalSum = 0;
    
    int maxEnding = arr[0], maxKadane = arr[0];
    int minEnding = arr[0], minKadane = arr[0];

    for (int i = 0; i < arr.size(); i++) {
        totalSum += arr[i];

        if (i > 0) {
            maxEnding = max(arr[i], maxEnding + arr[i]);
            maxKadane = max(maxKadane, maxEnding);

            minEnding = min(arr[i], minEnding + arr[i]);
            minKadane = min(minKadane, minEnding);
        }
    }

    // If all elements are negative
    if (maxKadane < 0)
        return maxKadane;

    return max(maxKadane, totalSum - minKadane);
    }
};