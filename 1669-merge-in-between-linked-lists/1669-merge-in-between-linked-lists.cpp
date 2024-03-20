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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int count = 1;
        ListNode* ptr= list1;
        while(count != a){
            count++;
            ptr = ptr->next;
        }
        ListNode *t = ptr; // stands before a
        while(count != b+1){
            count++;
            ptr = ptr->next;
        }
        ListNode *u = ptr->next;

        t->next = list2;
        // go to end of list2
        ptr = list2;
        while(ptr->next){
            ptr = ptr->next;
        }
        ptr->next = u;
        return list1;
    }
};