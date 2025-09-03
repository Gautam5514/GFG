/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
         if (!head) return NULL;

    Node* curr = head;
    Node* prevNode = NULL;

    // Traverse and swap prev & next for each node
    while (curr) {
        prevNode = curr->prev;
        curr->prev = curr->next;
        curr->next = prevNode;
        curr = curr->prev;  // move to next (originally next = prev)
    }

    // prevNode now points to the previous of NULL, i.e. last node
    if (prevNode) {
        head = prevNode->prev; // new head
    }

    return head;
    }
};