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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;

        set<int> s;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            if (s.find(curr->val) != s.end()) {
                prev->next = curr->next;
            }
            else {
                s.insert(curr->val);
                prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};