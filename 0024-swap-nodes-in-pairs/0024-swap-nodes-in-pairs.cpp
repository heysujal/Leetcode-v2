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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* ptr = head;
        while(ptr and ptr->next){
            swap(ptr->val, ptr->next->val);
            ptr = ptr->next->next;
        }
        return head;
    }
};