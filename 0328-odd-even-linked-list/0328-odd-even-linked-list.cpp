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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode* temp = head->next;
        ListNode* aux = temp;
        ListNode* ptr = head;
        while(temp and temp->next){
            ptr->next = temp->next;
            temp->next = ptr->next->next;
            ptr = ptr->next;
            temp = temp->next;
        }
        ptr->next = aux;
        return head;
    }
};