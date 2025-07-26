class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(auto num : arr) {
            mp[num]++;
        }
    
    for(auto it : mp) {
        if(it.second > n / 3) {
            ans.push_back(it.first);
        }
    }
        sort(ans.begin(), ans.end());
        return ans;
    }
};