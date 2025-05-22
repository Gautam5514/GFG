class Solution {
  public:
    int minDeletions(string s) {
        // code here
          int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        vector<int> dp1(n+1,0),dp2(n+1,0);
        string s2=s;
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp2[j]=1+dp1[j-1];
                }else{
                    dp2[j]=max(dp2[j-1],dp1[j]);
                }
            }
            dp1=dp2;
        }
    return n-dp2[n];
    }
};