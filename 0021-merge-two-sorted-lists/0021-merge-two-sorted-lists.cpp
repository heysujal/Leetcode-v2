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
    ListNode* mergeTwoLists(ListNode* p, ListNode* q) {
        ListNode* temp = new ListNode;
        auto aux = temp;
        // no need to write if(!p and !q) case
        if(!p)
            return q;
        if(!q)
            return p;
        // both p and q exists
        while(p and q){
            if(p->val <= q->val){
                temp->next = p;
                p = p->next;
                temp = temp->next;
            }
            else{
                temp->next = q;
                q = q->next;
                temp = temp->next;
            }
        }
        if(p)
            temp->next = p;
        if(q)
            temp->next = q;
        return aux -> next;
    }
};