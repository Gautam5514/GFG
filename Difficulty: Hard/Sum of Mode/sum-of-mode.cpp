class Solution {
  public:
    int sumOfModes(vector<int>& arr, int k) {
        // code here
         unordered_map<int,int>mp;
        set<pair<int,int>>st;
        
        int i=0,j=0,n=arr.size();
        int sum=0;
        while(j<n){
            // check if it is present in the map or not
            if(mp.find(arr[j])!=mp.end()){
                // find the set element
                int cnt=mp[arr[j]];
                st.erase({cnt,-1*arr[j]});
                
                // insert the new element in the set and in map
                st.insert({cnt+1,-1*arr[j]});
                mp[arr[j]]=cnt+1;
            } else{
                mp[arr[j]]++;
                st.insert({mp[arr[j]],-1*arr[j]});
            }
            
            if(j-i+1<k) j++;
            
            else if(j-i+1==k){
                // we have got a mode value
                // pick from the lowest in set and do it -1*arr[j]
                auto it=*st.rbegin();
                sum+=-1*(it.second);
                
                // now slide the window
                // before doing this in map, check for set also
                int cnt=mp[arr[i]];
                mp[arr[i]]--;
                st.erase({cnt,-1*arr[i]});
                if(mp[arr[i]]==0) {
                    mp.erase(arr[i]);
                } else{
                    st.insert({cnt-1,-1*arr[i]});
                }
                i++;
                j++;
            }
        }
        
        return sum;
    }
};