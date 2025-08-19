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
        ListNode* getKth(ListNode* head, int k) {
            while(head && k) {
                head = head->next;
                k--;
            }

            return head;
        }

    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* dummy = new ListNode(-1);
            dummy->next = head;

            ListNode* groupPrev = dummy;

            while(true) {
                ListNode* kth = getKth(groupPrev, k);

                if(!kth) break;

                ListNode* nextGroup = kth->next;
                ListNode* prev = kth->next;
                ListNode* curr = groupPrev->next;

                while(curr != nextGroup) {
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }

                ListNode* temp = groupPrev->next;
                groupPrev->next = kth;
                groupPrev = temp;
            }

            return dummy->next;
        }
};
