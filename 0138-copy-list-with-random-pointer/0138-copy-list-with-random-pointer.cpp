class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        // Step 1: Create copy of every node
        Node* temp = head;

        while (temp != nullptr) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Connect next and random pointers
        temp = head;

        while (temp != nullptr) {

            mp[temp]->next = mp[temp->next];

            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        return mp[head];
    }
};