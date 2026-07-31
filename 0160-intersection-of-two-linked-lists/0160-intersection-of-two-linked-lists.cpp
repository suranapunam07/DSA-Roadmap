/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head)
    {
        int count = 0;

        while(head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int lenA = length(headA);
        int lenB = length(headB);

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        if(lenA > lenB)
        {
            int diff = lenA - lenB;
            
            while(diff--)
            {
                p1 = p1->next;
            }
        } 
        else
        {
            int diff = lenB - lenA;

            while(diff--)
            {
                p2 = p2->next;
            }
        }
        while(p1 && p2)
        {
            if(p1 == p2)
            {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

/*
ListNode* tempA = headA;
        while(tempA != NULL)
        {
            ListNode* tempB = headB;

            while(tempB != NULL)
            {
                if(tempA == tempB)
                {
                    return tempA;
                }
                tempB = tempB->next;
            }
            tempA = tempA->next;
        }
        return NULL;
*/

/*
unordered_set<ListNode*> st;

        while(headA)
        {
            st.insert(headA);
            headA = headA->next;
        }
        while(headB)
        {
            if(st.find(headB) != st.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
*/