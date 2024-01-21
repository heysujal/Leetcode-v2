// to much condensed solution
class Solution {
public:
    // h hN sP
    // 0 1  2 3 4 5 6

    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        auto temp = head->next;
        head->next = swapPairs(head->next->next);
        temp->next = head;
        return temp;
    }
};