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
    int pairSum(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr != NULL)
        {
            ListNode* newnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newnode;
        }
         
        int maxSum = 0;

        ListNode* first = head;
        ListNode* second = prev;

        while(second != NULL)
        {
            int sum = first->val + second->val;
            maxSum = max(maxSum, sum);

            first = first->next;
            second = second->next;
        }
        return maxSum;
    }
};
/*
 vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int maxSum = 0;
        int n = arr.size();

        for(int i = 0; i < n / 2 ; i++)
        {
            int sum = arr[i] + arr[n - 1 - i];

            maxSum = max(maxSum, sum);
        }
        return maxSum;
*/