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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode(0, head);
        ListNode* dum1 = ans;

        while (dum1 != nullptr) {
            while (dum1->next != nullptr && dum1->next->val == val) {
                dum1->next = dum1->next->next;
            }
            dum1 = dum1->next;
        }
        
        ListNode* result = ans->next;
        delete ans;

        return result;     
    }
};