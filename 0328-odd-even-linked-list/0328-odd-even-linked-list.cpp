class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;    
        
        return head;
    }
};

/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr)
            return head;

        ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);

        ListNode* oddTail = oddDummy;
        ListNode* evenTail = evenDummy;

        int pos = 1;

        while (head) {

            if (pos % 2 == 1) {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
            else {
                evenTail->next = head;
                evenTail = evenTail->next;
            }

            head = head->next;
            pos++;
        }

        evenTail->next = nullptr;
        oddTail->next = evenDummy->next;

        return oddDummy->next;
    }
};
*/