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
    // 1 pass solution
    // Algo. move k times find p1
    // Now set p2 to head and keep moving ptr and p2
    // till ptr becomes null
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head;
        ListNode *p1 = nullptr;
        ListNode *p2 = nullptr;

        while(ptr){
            if(p2){
                p2 = p2->next;
            }
            k--;
            if(k==0){
                p1 = ptr;
                p2 = head; // activate p2 to start moving
            }
            ptr = ptr->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};