class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int i = 0;
        int j = arr2.size() - 1;
        
        int diff = INT_MAX;
        
        vector<int> result(2);
        
        while(i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j];
            int currDiff = abs(sum - x);
            
            if(currDiff < diff) {
                diff = currDiff;
                result[0] = arr1[i];
                result[1] = arr2[j];
            }
            
            if(sum > x)
                j--;
            else
                i++;
        }
        return result;
    }
};