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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // find mid
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at mid, reverse it from here 
        // and make slow->next = nullptr to seperate it

        ListNode* ptr = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = ptr;
            ptr = curr;
            curr = next;
        }
        slow->next = nullptr;
        
        // prev will be head of second linked list
        
        ListNode* p = head;
        ListNode* q = ptr;
        while(p and q){
            if(p->val != q->val){
                return false;
            }
            p = p->next;
            q = q->next;
        }

        return true; 
    }
};