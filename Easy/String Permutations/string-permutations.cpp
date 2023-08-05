//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void permute(string& s, vector<string>& ans, int index) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);
            permute(s, ans, index + 1);
            swap(s[index], s[i]); // Backtrack to restore the original order
        }
    }
    public:
    vector<string> permutation(string S)
    {
        vector<string> ans;
        permute(S, ans, 0);
        sort(ans.begin(), ans.end()); // Sort the permutations in lexicographically increasing order
        return ans;
}
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends