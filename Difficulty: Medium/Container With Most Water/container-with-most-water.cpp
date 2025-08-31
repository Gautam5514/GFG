class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
            int n = arr.size();
        int left = 0, right = n - 1;
        int maxWater = 0;

        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxWater = max(maxWater, height * width);

            // Move the pointer at the smaller line
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};