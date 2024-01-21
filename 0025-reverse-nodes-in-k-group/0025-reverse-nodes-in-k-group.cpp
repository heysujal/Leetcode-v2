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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head or !head->next)
            return head;

        // idea is to iterate first K nodes manually
        //1. first we check if K nodes are available or not?
        ListNode *checker = head;
        for(int i = 0; i < k; i++){
            if(!checker){
                return head; // can' be reversed bcoz less than k nodes
            }  
            checker = checker->next;
        }

        // Confirmed, we have >= k nodes to reverse 
        // Now, swap first k nodes manually iteratively
        int t = k;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(curr and t--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(next){
            auto rest_head = reverseKGroup(next, k);
            head->next = rest_head;
        }
        return prev;
    }
};