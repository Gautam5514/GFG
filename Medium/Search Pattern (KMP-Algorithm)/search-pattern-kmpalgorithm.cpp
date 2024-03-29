//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int n= txt.length();
            int m= pat.length();
            int len=0;
            vector<int>arr(m,0);
            
            int i=1;
            while(i<m){
                if(pat[i]==pat[len]){
                    arr[i]=len+1;
                    len++;
                    i++;
                }
                else{
                    if(len==0){
                        arr[i]=0;
                        i++;
                    }
                    else{
                        len = arr[len-1];
                    }
                }
            }
            
            // for(auto )
            
            i=0; 
            int j=0;
            vector<int>ans;
            while(i<n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    ans.push_back(i-j+1);
                    j=arr[j-1];
                }
                else if(i<n && pat[j] != txt[i]){
                    if(j==0){
                        i++;
                    }
                    else{
                        j=arr[j-1];
                    }
                }
            }
            
            if(ans.size()==0){
                return {-1};
            }
            
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends