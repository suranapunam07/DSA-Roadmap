class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        vector<int> arr;

        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};