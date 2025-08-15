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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* temp1 = l1;
            ListNode* temp2 = l2;

            int carry = 0;

            ListNode* newList = new ListNode(-1);
            ListNode* temp = newList;

            while(temp1 && temp2) {
                int sum = temp1->val + temp2->val + carry;
                temp->next = new ListNode(sum % 10);
                carry = sum / 10;

                temp1 = temp1->next;
                temp2 = temp2->next;
                temp = temp->next;
            }

            while(temp1) {
                int sum = temp1->val + carry;
                temp->next = new ListNode(sum % 10);
                carry = sum / 10;

                temp1 = temp1->next;
                temp = temp->next;
            }

            while(temp2) {
                int sum = temp2->val + carry;
                temp->next = new ListNode(sum % 10);
                carry = sum / 10;

                temp2 = temp2->next;
                temp = temp->next;
            }

            if(carry) {
                temp->next = new ListNode(carry);
            }

            return newList->next;
        }
};
