//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 vector<vector<int>> dirs;
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    int l=word.size();
	    vector<vector<int>> ans;
	    dirs={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++){
	            if(word[0]!=grid[i][j])continue;
	            if(dfs(grid,m,n,word,l,i,j))ans.push_back({i,j});
	        }
	    }
	    return ans;
	}
	int dfs(vector<vector<char>>& grid,int m,int n,string word,int l,int i,int j){
	    for(auto it:dirs){
	        int k=0;
	        for(int r=i,c=j;min(r,c)>=0 && r<m && c<n && k<l && grid[r][c]==word[k];k++,r+=it[0],c+=it[1]);
	        if(k==l)return 1;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends