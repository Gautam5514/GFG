class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
          int n=s.size();
        unordered_map<char,pair<int,int>>mp;
        vector<int>ans(n,0);
        ans[0]=int(s[0]);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+int(s[i]);
           
        }
        for(int i=0;i<n;i++){
             if(mp.find(s[i])!=mp.end()){
                mp[s[i]].second=i;
            }
            else
            mp[s[i]]={i,i};
        }
        vector<int>res;
        for(char ch='a';ch<='z';ch++){
            if(mp.find(ch)!=mp.end() && mp[ch].first!=mp[ch].second){
                int l=mp[ch].first,r=mp[ch].second;
                if(r-l>1){
                    int sum=ans[r-1]-ans[l];
                    res.push_back(sum);
                }
            }
        }
        return res;
    }
};