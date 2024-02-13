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
    ListNode* addTwoNumbers(ListNode* p, ListNode* q) {
        ListNode* temp = new ListNode();
        ListNode* aux = temp;
        bool carry = false;
        while(p and q){
            int val = p->val + q->val + carry;
            int d = val % 10;
            carry = val > 9;
            temp->next = new ListNode(d);
            temp = temp->next;
            p = p->next;
            q = q->next;
        }
        while(p){
            int val = p->val + carry;
            int d = val % 10;
            carry = val > 9;
            temp->next = new ListNode(d);
            temp = temp->next;
            p = p->next;
        }
        while(q){
            int val = q->val + carry;
            int d = val % 10;
            carry = val > 9;
            temp->next = new ListNode(d);
            temp = temp->next;
            q = q->next;
        }
        if(carry){
            temp->next = new ListNode(1);
        }
        return aux->next;
    }
};