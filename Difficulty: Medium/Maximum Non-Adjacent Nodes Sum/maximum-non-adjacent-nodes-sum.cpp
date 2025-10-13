/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  unordered_map<Node*, int> dp;
  int sum(Node* root) {
      if(root == NULL ) return 0;
      if(dp[root]) return dp[root];
      int ll = (root->left != NULL) ? sum(root->left->left) : 0;
      int lr = (root->left != NULL) ? sum(root->left->right) : 0;
      int rl = (root->right != NULL) ? sum(root->right->left) : 0;
      int rr = (root->right != NULL) ? sum(root->right->right) : 0;
      int take = (root->data) + ll + lr + rl + rr;
      int leave = sum(root->left) + sum(root->right);
      return dp[root] =  max(take, leave);
  }
    int getMaxSum(Node *root) {
        // code here
        return sum(root);
    }
};