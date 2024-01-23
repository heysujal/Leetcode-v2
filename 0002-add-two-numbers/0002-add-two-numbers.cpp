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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *temp = new ListNode();
        ListNode *aux = temp;
        while(l1 and l2){
            int x = l1->val + l2->val + carry; // (can become 19 at max)
            temp->next = new ListNode(x%10);
            carry = x/10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
            // if there is a carry
        while(l1){
            int x = l1->val + carry;
            carry = x/10;
            temp->next = new ListNode(x%10);
            l1 = l1->next;
            temp = temp->next;
        }
        
        while(l2){
            int x = l2->val + carry;
            carry = x/10;
            temp->next = new ListNode(x%10);
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return aux->next;
    }
};