class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.length();
        
        unordered_map<char, int> mp;
        
        int start = 0; 
        int maxLength = -1;
        
        for(int i = 0; i< n; i++) {
            mp[s[i]]++;
            
            // check the kthe substring are present or not
            while(mp.size() > k) {
                mp[s[start]]--;
                
                if(mp[s[start]] == 0) 
                mp.erase(s[start]);
                start++;
            }
            if(mp.size() == k) {
                maxLength = max(maxLength, i - start + 1);
            }
        }
        return maxLength;
    }
};