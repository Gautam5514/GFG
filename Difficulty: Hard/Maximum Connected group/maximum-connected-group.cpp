//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    int dfs(int x,int y,int n,int uId,vector<vector<int>>& grid){
        if(x>n-1 or y>n-1 or x<0 or y<0 or grid[x][y]!=1)
            return 0;
        grid[x][y]=uId;
        int cnt=1;
        for(int i=0;i<4;i++)
            cnt+=dfs(x+dx[i],y+dy[i],n,uId,grid);
        return cnt;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        int uId=2,ans=0; // uId: group/component unique id
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mp[uId]=dfs(i,j,n,uId,grid);
                    ans=max(ans,mp[uId]);
                    uId++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int ni=i+dx[k],nj=j+dy[k];
                        if(ni<n and nj<n and ni>-1 and nj>-1 and grid[ni][nj]!=0)
                            st.insert(grid[ni][nj]);
                    }
                    int currAns=0;
                    for(int i:st)
                        currAns+=mp[i];
                    ans=max(ans,currAns+1);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends