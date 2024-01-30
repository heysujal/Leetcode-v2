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
    bool hasCycle(ListNode *head) {
        ListNode* ptr = head;
        while(ptr){
            if(ptr->val == 1e9){
                return true;
            }
            ptr->val = 1e9;
            ptr = ptr->next;
        }
        return false;
    }
};