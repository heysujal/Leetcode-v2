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
    // brute
    ListNode* swapNodes(ListNode* head, int k) {
        auto ptr = head;
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        int n = 0;
        while(ptr){
            n++;
            ptr = ptr->next;
        }
        // overwriting the existing LinkedList
        int i = -1;
        ptr = head;
        while(ptr){
            i++;
            if(i == k-1){
                p1 = ptr;
            }
            if(i == n-k){
                p2 = ptr;
            }
            ptr = ptr->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};