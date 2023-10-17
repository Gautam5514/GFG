//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void setDfs(vector<int> adj[], vector<int> &visited, int index){
        visited[index] = 1;
        for(auto x: adj[index]){
            if(visited[x] != 1){
                setDfs(adj, visited,x);
            }
        }
        return;
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(i != j && graph[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < N; i++){
            vector<int> visited(N, 0);
            visited[i] = 1;
            setDfs(adj, visited, i);
            ans.push_back(visited);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends