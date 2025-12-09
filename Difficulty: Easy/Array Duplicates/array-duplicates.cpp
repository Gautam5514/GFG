class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(auto x : arr) {
            mp[x]++;
        }
        
        for(auto it : mp) {
            if(it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};