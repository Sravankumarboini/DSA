class Solution {
    public:
        void deleteNode(ListNode* node) {
            ListNode* temp=node;
            temp=temp->next;
            node->val=temp->val;
            node->next=temp->next;
        delete temp;
        }
    };