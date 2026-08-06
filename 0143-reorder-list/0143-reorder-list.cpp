class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL)
        {
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = reverse(slow->next);
        slow->next = NULL;
        ListNode* first = head;

        while(second != NULL)
        {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
        
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};