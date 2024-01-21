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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;
        auto A = head;
        auto B = A->next;
        auto res = reverseList(B); // gives 5 4 3 2 in res
        B->next = A;
        A->next = nullptr;
        return res;
    }
};