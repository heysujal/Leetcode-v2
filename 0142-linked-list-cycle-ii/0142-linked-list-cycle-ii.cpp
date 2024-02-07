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
    // using u_map
    ListNode *detectCycle(ListNode *head) {
        // ask interviwer 
        // does this have unique values?, if yes store values instead of node in set

        unordered_set<ListNode*> st;
        ListNode* ptr = head;
        while(ptr){
            if(st.count(ptr)){
                return ptr;
            }
            st.insert(ptr);
            ptr = ptr->next;
        }
        return nullptr;
    }
};