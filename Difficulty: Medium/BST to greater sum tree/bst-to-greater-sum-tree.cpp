/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
  int sum;
    void transformTree(Node *root) {
        // code here
        sum = 0;
       BST(root);
    }
    void BST(Node* root) {
        if(root == NULL) return;
        BST(root -> right);
        int SumAll = root -> data;
        root -> data = sum;
        sum += SumAll;
        BST(root -> left);
    }
};