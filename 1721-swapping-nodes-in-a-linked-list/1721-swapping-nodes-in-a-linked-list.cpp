class Solution {
public:
    // 1 pass solution
    // Algo. 
    // Point p1 to kth node
    // then, start ptr from p1->next and p2 from head
    // till ptr becomes null
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr = head;
        ListNode *p1 = nullptr;
        ListNode *p2 = nullptr;
        k = k-1;

        while(k--){
            ptr = ptr->next;
        }
        p1 = ptr;
        ptr = ptr->next;
        p2 = head;
        while(ptr){
            ptr = ptr->next;
            p2 = p2->next;
        }
        swap(p1->val, p2->val);
        return head;
    }
};