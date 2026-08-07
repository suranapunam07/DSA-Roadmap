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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        int n = 0;
        ListNode* temp = head;

        while(temp)
        {
            n++;
            temp = temp->next;
        }

        k = k % n;

        while(k--)
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            
            while(curr->next)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }
        return head;
    }
};

/*
ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        vector<ListNode*> arr;
        ListNode* temp = head;

        while(temp)
        {
            arr.push_back(temp);
            temp = temp->next;
        }
        int n = arr.size();
        k %= n;
        if(k == n)
        {
            return head;
        }
        ListNode* newHead = arr[n - k];
        ListNode* newTail = arr[n - k -1];

        arr[n - 1]->next = head;

        newTail->next = NULL;

        return newHead;
*/