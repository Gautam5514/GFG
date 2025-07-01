class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char, int> alp;
        int n = s.size();
        string str = "";
        int ans = 0;
        for(int i = 0; i < n; i++) {
            str += s[i];
            alp[s[i]]++;
            
            if(str.length() == k) {
                if(alp.size() == k - 1) ans++;
                alp[str[0]]--;
                
                if(alp[str[0]] == 0) alp.erase(str[0]);
                str.erase(0, 1);
            }
        }
        return ans;
    }
}; 