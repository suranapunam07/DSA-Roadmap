class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers
        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove nth node
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummy->next;
    }
};