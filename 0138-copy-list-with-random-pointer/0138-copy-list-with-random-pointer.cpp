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
    // Algo : 
    // 1. insert new nodes in between
    // 2. Copy the random pointer
    // 3. Copy the next pointer
    Node* copyRandomList(Node* head) {
        // Step 1
        Node* ptr = head;
        while(ptr){
            Node* copyNode = new Node(ptr->val);
            copyNode->next = ptr->next;
            ptr->next = copyNode;
            ptr = ptr->next->next; // moving to next original node
        }
        // Step 2 
        ptr = head;
        while(ptr){
            auto copyNode = ptr->next;
            if(ptr->random){
                copyNode->random = ptr->random->next; // points to copy of ptr->random's node
            }
            else{
                copyNode->random = nullptr;
            }
            ptr = ptr->next->next; // moving to next original node
        }
        // Step 3
        Node* temp = new Node(-1);
        Node* aux = temp;
        ptr = head;
        while(ptr){
            temp->next = ptr->next;
            temp = temp->next; // jumps to copy node
            // disconnecting copy Nodes and 
            // reverting to original state
            ptr->next = ptr->next->next;
            ptr = ptr->next;
        }
        return aux->next;
    }
};