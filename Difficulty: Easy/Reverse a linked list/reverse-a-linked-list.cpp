/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* dummyNode = NULL;
        Node* curr = NULL;
        
        while(head != NULL) {
            curr = head -> next;
            head -> next = dummyNode;
            dummyNode = head;
            head = curr;
        }
        return dummyNode;
    }
};