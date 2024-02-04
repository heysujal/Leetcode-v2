/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *findNthNode(ListNode* temp, int moves){
        ListNode* ptr = temp;
        while(ptr and moves){
            ptr = ptr->next;
            moves--;
        }
        return ptr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next or k == 0)
            return head;
        
        int len = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            len++;
        } 
        k = k % len;
        if(k == 0)
            return head;

        // make linked list circular
        tail->next = head;
        // find effective k
        // now, the node at len - k from tail will be our new last node
        ListNode* newLastNode = findNthNode(tail, len - k);
        head = newLastNode->next;
        newLastNode->next = nullptr;
        return head;
    }
};