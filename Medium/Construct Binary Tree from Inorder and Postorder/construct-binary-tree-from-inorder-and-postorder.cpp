//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    // Node *buildTree(int in[], int post[], int n) {
    //     // Your code here
    // }
 Node* solve(int in[], int pos[], int inStart, int inEnd, int posStart, int posEnd){
        if(inStart>inEnd) return NULL;
        if(inStart==inEnd){
            return new Node(in[inStart]);
        }
        Node* root= new Node(pos[posEnd]);
        int ind = -1;
        for(int i=inStart;i<=inEnd;i++){
            if(in[i]==pos[posEnd]){
                ind=i;
                break;
            }
        }
        int left=ind-inStart;
        int right=inEnd-ind;
        
        root->left=solve(in, pos, inStart,ind-1, posStart, posStart+left-1);
        root->right=solve(in, pos, ind+1, inEnd, posEnd-right, posEnd-1);
        
        return root;
    }
    

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        return solve(in, post, 0, n-1, 0, n-1);
        
    }

};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends