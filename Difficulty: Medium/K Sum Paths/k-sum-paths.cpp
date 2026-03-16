/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int dfs(Node* root, long long currSum, int k, unordered_map<long long,int>& mp){
        
        if(root == NULL) return 0;
        
        currSum += root->data;
        
        int count = 0;
        
        // check if prefix exists
        if(mp.find(currSum - k) != mp.end()){
            count += mp[currSum - k];
        }
        
        // store current sum
        mp[currSum]++;
        
        // explore left and right
        count += dfs(root->left, currSum, k, mp);
        count += dfs(root->right, currSum, k, mp);
        
        // backtrack
        mp[currSum]--;
        
        return count;
    }
  
    int countAllPaths(Node *root, int k) {
        
        unordered_map<long long,int> mp;
        
        mp[0] = 1;   // important base case
        
        return dfs(root, 0, k, mp);
    }
};