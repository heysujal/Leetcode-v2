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
    // slow and fast method (hint: cycle question)
    // Algo
    // detect cycle using slow and fast where they meet
    // now move any of them to head and keep moving by one step.
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head->next)
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                // cycle is detected
                // now we move one step at a time
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};