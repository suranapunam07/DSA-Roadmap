class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int count = 0;
        ListNode* temp = head;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        // Delete head
        if(count == n)
        {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;

        // Move to the previous node
        for(int i = 1; i < count - n; i++)
        {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};