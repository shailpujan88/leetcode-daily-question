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
    void insertIntoTail(ListNode*& Head, ListNode*& Tail, int data) {
        if (Head == NULL) {
            ListNode* newNode = new ListNode(data);
            Head = newNode;
            Tail = newNode;
            return;
        }
        ListNode* newNode = new ListNode(data);
        Tail->next = newNode;
        Tail = newNode;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* Y = lists[i];

            ListNode* temp = Y;
            while (temp != NULL) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(arr.begin(), arr.end());

        ListNode* Head = NULL;
        ListNode* Tail = NULL;
        for (int i = 0; i < arr.size(); i++) {
            insertIntoTail(Head, Tail, arr[i]);
        }

        return Head;
    }
};