//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
     int mini=INT_MAX;
    
    void dfs(vector<vector<int>>&mat,int row,int col,vector<vector<int>>&visited,int count){
        
    if(row<0 || col<0 || col>=mat[0].size() || row>=mat.size()|| visited[row][col] || 
    row+1<mat.size() and mat[row+1][col]==0 || row-1>=0 and mat[row-1][col]==0 ||
    col+1<mat[0].size() and mat[row][col+1]==0 || col-1>=0 and mat[row][col-1]==0 
    || mat[row][col]==0)return;


        if(col==mat[0].size()-1){
            mini=min(mini,count+1);
            return;
        }
            visited[row][col]=1;
        dfs(mat,row+1,col,visited,count+1);
        dfs(mat,row-1,col,visited,count+1);
        dfs(mat,row,col+1,visited,count+1);
        dfs(mat,row,col-1,visited,count+1);
            visited[row][col]=0;
    }
    
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(mat,i,0,visited,0);
        }
        if(mini==INT_MAX)return -1;
        
        return mini;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends