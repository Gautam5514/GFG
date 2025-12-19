class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int allSum = (long long) (n + 1) * (n + 2) / 2;
        int arrSum = 0;
        
        for(auto x : arr) {
            arrSum += x;
        }
        return allSum - arrSum;
    }
};