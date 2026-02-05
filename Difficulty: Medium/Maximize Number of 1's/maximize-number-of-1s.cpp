class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
          int n = arr.size();

    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {

        // If current element is 0 → increase zero count
        if (arr[right] == 0)
            zeroCount++;

        // If zeros exceed k → shrink window from left
        while (zeroCount > k) {
            if (arr[left] == 0)
                zeroCount--;
            left++;
        }

        // Update maximum length of valid window
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
    }
};
