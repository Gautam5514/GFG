class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        int currSum = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            int needed = currSum - k;
            if(mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            mp[currSum]++;
        }
        return count;
    }
};