//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &St){
    stack<int> t1,t2;
    
    // Move elements from St to t1
    while (!St.empty()) {
        int curr = St.top();
        St.pop();
        t1.push(curr);
    }
    
    // Move elements from t1 to t2
    while (!t1.empty()) {
        int curr = t1.top();
        t1.pop();
        t2.push(curr);
    }
    
    // Move elements from t2 back to St (which will be the reversed order)
    while (!t2.empty()) {
        int curr = t2.top();
        t2.pop();
        St.push(curr);
    }
}

};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends