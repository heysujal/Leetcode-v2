/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int length(ListNode *head){
        int len = 0;
        ListNode* ptr = head;
        while(ptr){
            len++;
            ptr = ptr->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *p, ListNode *q) {
        int m = length(p);
        int n = length(q);
        int diff = abs(m-n);
        // cover the diff for whoever is longer
        if(m > n){
            while(diff--){
                p = p->next;
            }
        }
        else{
            while(diff--){
                q = q->next;
            }
        }
        while(p and q){
            if(p == q){
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};