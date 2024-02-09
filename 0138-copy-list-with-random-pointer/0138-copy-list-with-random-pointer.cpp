/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    // algo
    // insert nodes in b/w
    // copy random pointer
    // copy next pointer

    Node* copyRandomList(Node* head) {
        Node *og = head;
        while(og){
            Node* copy = new Node(og->val);
            copy->next = og->next;
            og->next = copy;
            og = copy->next;
        }   

        // copy random pointer
        og = head;
        while(og){
            if(og->random){
                og->next->random = og->random->next;
            }
            else{
                og->next->random = nullptr;
            }
            og = og->next->next;
        }

        // copy next pointer
        og = head;
        Node* temp = new Node(0);
        Node* aux = temp;
        while(og){
            //imp. to use temp this way maybe coz of single node case
            temp->next = og->next;
            temp = temp->next;
            //...imp.
            og->next = og->next->next;
            og = og->next;
        }
        return aux->next;
    }
};