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
        vector<int> v;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = v.size();
        swap(v[k-1], v[n-k]);
        // overwriting the existing LinkedList
        int i = 0;
        ptr = head;
        while(ptr){
            ptr->val = v[i++];
            ptr = ptr->next;
        }
        return head;
    }
};