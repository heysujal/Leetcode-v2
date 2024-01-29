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
    int getSize(ListNode *head){
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        int k = size - n;
        ListNode* p = nullptr;
        ListNode* q = head;
        if(k == 0){
            // means delete 1st node
            return head->next;
        }
        while(k != 0){
            k--;
            p = q;
            q = q->next;
        }
        p->next = q->next;
        return head;
    }
};