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

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {

        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        while(head)
        {

            if(head->val < x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }

            head = head->next;
        }

        large->next = nullptr;

        small->next = largeDummy->next;

        return smallDummy->next;
    }
};

/*
  vector<int> small, large;
        ListNode* temp = head;

        while(temp)
        {
            if(temp->val < x)
            {
                small.push_back(temp->val);
            }
            else
            {
                large.push_back(temp->val);
            }
            temp = temp->next;   
        }
        temp = head;

        for(int val : small)
        {
            temp->val = val;
            temp = temp->next;
        }
        for(int val: large)
        {
            temp->val = val;
            temp = temp->next;
        }
        return head;
*/