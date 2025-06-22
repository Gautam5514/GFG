class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        // Code here
         int n=arr.size();
        sort(arr.rbegin(),arr.rend());
        int parent=-1;
        int maxi=0;
        vector<int>par(n,-1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((arr[j]%arr[i])==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        par[i]=j;
                    }
                }
            }
            
            if(dp[i]>maxi){
                parent=i;
                maxi=dp[i];
            }
        }
        vector<int>res;
        while(parent!=-1){
            res.push_back(arr[parent]);
            parent=par[parent];
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};