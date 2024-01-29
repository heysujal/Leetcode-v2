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
    ListNode *getIntersectionNode(ListNode *p, ListNode *q) {
        unordered_map<ListNode*, bool> mp;
        while(p){
            mp[p] = true;
            p = p->next;
        }
        while(q){
            if(mp[q]){
                return q;
            }
            q = q->next;
        }
        return nullptr;
    }
};