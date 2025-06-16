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
        Node* dummy = NULL;
        while(head != NULL) {
            Node* curr = head -> next;
            head -> next = dummy;
            dummy = head;
            head = curr;
        }
        return dummy;
    }
};