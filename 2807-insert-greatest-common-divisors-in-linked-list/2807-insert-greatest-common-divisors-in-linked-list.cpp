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
    int gcd(int a, int b){
        int res = min(a, b);
        while(res > 0){
            if(a % res == 0 and b % res == 0){
                break;
            }
            res--;
        }
        return res;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while(p1 and p2){
            int hcf = gcd(p1->val, p2->val);
            cout<< hcf;
            p1->next = new ListNode(hcf);
            p1->next->next = p2;
            p1 = p2;
            p2 = p1->next;
        }
        return head;
    }
};