/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  int ans = -1;
  void solve(Node* root, int k) {
      if(root == NULL)
        return;
      if(root -> data <= k) {
          ans = root -> data;
          solve(root -> right, k);
      } else {
          solve(root -> left, k);
      }
  }
    int findMaxFork(Node* root, int k) {
        // code here
        solve(root, k);
        return ans;
    }
};