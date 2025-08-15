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
    private:
        ListNode* reverse(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;

            while(curr) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

    public:
        void reorderList(ListNode* head) {
            if(!head || !head->next) return;

            ListNode* slow = head;
            ListNode* fast = head->next;

            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode* second = slow->next;
            slow->next = nullptr;

            ListNode* first = head;
            second = reverse(second);

            while(second) {
                ListNode* t1 = first->next;
                ListNode* t2 = second->next;

                first->next = second;
                second->next = t1;
                first = t1;
                second = t2;
            }
        }
};
